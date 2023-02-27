from pathlib import Path
import matplotlib.pyplot as plt


class Operations(dict):
    def add(self, block: dict):
        operation = block['operation']
        collection = block['collection']
        vals = {'elems': block['elems_num'], 'time': block['time']}
        if operation in self:
            if collection in self[operation]:
                self[operation][collection].append(vals)
            else:
                self[operation][collection] = [vals]
        else:
            self[operation] = {collection: [vals]}

    def sort(self):
        for operation in self.values():
            for collection_elems in operation.values():
                collection_elems.sort(key=lambda x: x['elems'])


def plot(filename, op_name, op_val):
    plt.style.use('Solarize_Light2')
    ax = plt.subplot()
    for name, vals in op_val.items():
        x = tuple(int(i['elems']) for i in vals)
        y = tuple(int(i['time']) for i in vals)
        ax.plot(x, y, label=name)
    ax.grid(True, linestyle='--')
    ax.set_title(f'comparing {op_name} of {tuple(op_val.keys())}')
    ax.set_xlabel('elements', loc='right')
    ax.set_ylabel('time (ms)', loc='top')
    ax.legend()
    plt.savefig(f'{Path(filename).name[:-len(Path(filename).suffix)]}_{op_name}.png')


def load(filename: str) -> Operations:
    strings = list(i.rstrip() for i in open(filename).readlines())
    while not strings[-1]:
        strings.pop()
    operations = Operations()
    block = {}
    for s in strings:
        if not s:
            operations.add(block)
            block = {}
            continue
        k, v = s.split(' ')
        block[k] = v
    operations.add(block)
    return operations


if __name__ == '__main__':
    filename = input('Fielname: ') or 'tests/map-unordered_map.txt'
    ops = load(filename)
    ops.sort()
    for op_name, op_val in ops.items():
        plot(filename, op_name, op_val)

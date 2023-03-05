from pathlib import Path
import matplotlib.pyplot as plt


class Operations(dict):
    def add(self, block: dict):
        operation = block['operation']
        collection = block['collection']
        vals = {'elems': int(block['elems_num']), 'time': int(block['time'])}
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


def plot(filename, op_name, op_val, *collection_names):
    ax = plt.subplot()
    for name in collection_names:
        vals = op_val[name]
        x = tuple(i['elems'] // 100_000 for i in vals)
        y = tuple(i['time'] for i in vals)
        ax.plot(x, y, label=name)
    ax.grid(True, linestyle='--')
    ax.set_title(f'{op_name.replace("_", " ")}')
    ax.set_xlabel('количество пар целочисленных типов * 100.000', loc='right')
    ax.set_ylabel('время (мс)', loc='top')
    ax.legend()
    plt.savefig(f'{Path(filename).name[:-len(Path(filename).suffix)]}_{op_name}.png')
    plt.close()


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
    from pprint import pprint
    filename = input('Filename: ') or 'tests/map-unordered_map.txt'
    ops = load(filename)
    ops.sort()
    for op_name, op_val in ops.items():
        plot(filename, op_name, op_val, "map", "umap")

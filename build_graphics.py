from pathlib import Path
import matplotlib.pyplot as plt

from pprint import pprint


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
    plt.savefig(f'nani/{Path(filename).name[:-len(Path(filename).suffix)]}_{op_name}.png')
    plt.close()


def percentage_plot(filename, op_name, op_val, *collection_names):
    types = collection_names[:2]
    x = tuple(i['elems'] // 100_000 for i in op_val[types[0]])
    y = []
    for i in range(len(op_val[types[0]])):
        y1 = op_val[types[0]][i]['time']
        y2 = op_val[types[1]][i]['time']
        y.append((y1 - y2) / (y1 + y2) * 100)
    ax = plt.subplot()
    ax.bar(x, y, label=f'разница {collection_names}', width=2)
    ax.grid(True, linestyle='--')
    ax.set_title(f'{op_name.replace("_", " ")}')
    ax.set_xlabel('количество пар целочисленных типов * 100.000', loc='right')
    ax.set_ylabel(f'%', loc='top')
    ax.legend()
    plt.savefig(f'nani/{Path(filename).name[:-len(Path(filename).suffix)]}_{op_name}.png')
    plt.close()


if __name__ == '__main__':
    filename = input('Filename: ') or 'tests/map-unordered_map.txt'
    ops = load(filename)
    ops.sort()
    # for op_name, op_val in ops.items():
    #     plot(filename, op_name, op_val, "map", "umap")
    for op_name, op_val in ops.items():
        percentage_plot(filename, op_name, op_val, "map", "umap")

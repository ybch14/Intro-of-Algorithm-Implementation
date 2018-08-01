import numpy as np
data = 2e6 * np.random.rand(int(1e6)) - 1e6
data = list(set(list(data)))
sorted_data = sorted(data)
rank = {k: v for k, v in zip(sorted_data, range(len(sorted_data)))}
# print(rank)
query = np.random.choice(data, size=int(1e5), replace=False)
query_rank = [rank[i] for i in query]

fp = open('data.txt', 'w')
[fp.write('%f\n' % i) for i in data]
fp.close()

fp = open('query.txt', 'w')
[fp.write('%f %d\n' % i) for i in zip(query, query_rank)]
fp.close()
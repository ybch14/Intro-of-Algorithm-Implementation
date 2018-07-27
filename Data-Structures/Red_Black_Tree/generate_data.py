import numpy as np
data = 2e6 * np.random.rand(int(1e5)) - 1e6
query_length = np.random.randint(int(3e4), high=int(1e5))
np.random.shuffle(data)
sure_query = data[:query_length]
sure_query_gt = np.array([1] * query_length)
notsure_query = 2e6 * np.random.rand(int(1e5) - query_length) - 1e6
notsure_query_gt = np.array([int(i in data) for i in notsure_query])
query_seq = zip(sure_query, sure_query_gt) + zip(notsure_query, notsure_query_gt)
np.random.shuffle(query_seq)

fp = open('random_data.txt', 'w')
[fp.write('%f\n' % i) for i in data]
fp.close()

partly_sorted_data = data
partly_sorted_data[int(2e4):int(6e4)] = sorted(partly_sorted_data[int(2e4):int(6e4)])
fp = open('partly_sorted_data.txt', 'w')
[fp.write('%f\n' % i) for i in partly_sorted_data]
fp.close()

totally_sorted_data = sorted(data)
fp = open('totally_sorted_data.txt', 'w')
[fp.write('%f\n' % i) for i in totally_sorted_data]
fp.close()

fp = open('query.txt', 'w')
[fp.write('%f %d\n' % (value, gt)) for value, gt in query_seq]
fp.close()
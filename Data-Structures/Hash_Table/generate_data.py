import numpy as np
string_number = np.random.randint(int(1), high=int(7e5), size=int(3e5))
string_number = np.array(string_number, dtype=np.float32)
string_number /= np.sum(string_number)
string_number *= 1e6
string_number = np.array(string_number, dtype=np.int32)
string_number[string_number == 0] = 1
add_index = np.random.randint(int(0), high=int(3e5-1), size=int(1e6 - np.sum(string_number)))
for index in add_index:
	string_number[index] += 1
# string_number: appear time of each string 
distinct_strings = []
strings = []
# string_length: length of each string
string_length = np.random.randint(int(1), int(100), size=int(3e5))
import random 
import string
while len(distinct_strings) < 3e5:
	offset = len(distinct_strings)
	for i in range(int(3e5) - len(distinct_strings)):
		s = ''.join([random.choice(string.ascii_letters + string.digits) for n in range(string_length[(i + offset) % int(3e5)])])
		distinct_strings.append(s)
	distinct_strings = list(set(distinct_strings))
	print(len(distinct_strings))
for i in range(int(3e5)):
	s = distinct_strings[i]
	[strings.append(s) for _ in range(string_number[i])]
np.random.shuffle(strings)
print(len(strings))
fp = open('data.txt', 'w')
for s in strings:
	fp.write('%s\n' % s)
fp.close()
fp = open('ground_truth.txt', 'w')
for s, n in zip(distinct_strings, string_number):
	fp.write('%s %d\n' % (s, n))
fp.close()
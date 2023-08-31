import numpy as np
from scipy.sparse import coo_array

row = np.array([0, 1, 2, 3, 4, 1, 2, 3, 4])
col = np.array([0, 1, 2, 3, 4, 0, 0, 0, 0])
data = np.array([9, 0.5, 12, 0.625, 16, 1.5, 6, 0.75, 3])
coo = coo_array((data, (row, col)), shape=(5, 5))

print("coo.toarray()")
print(coo.toarray())

csr = coo.tocsr()

print("\ncsr.toarray()")
print(csr.toarray())

print("\nrow_pointers")
print(csr.indptr)
print("\ncolumn_indices")
print(csr.indices)
print("\nvalues")
print(csr.data)

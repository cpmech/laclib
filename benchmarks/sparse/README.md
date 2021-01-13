# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.

## pre2 matrix with 1 proc

```
Entering DMUMPS 5.3.5 from C interface with JOB, N, NNZ =   1      659033        5959282
      executing #MPI =      1, without OMP

 =================================================
 MUMPS compiled with option -Dmetis
 MUMPS compiled with option -Dparmetis
 MUMPS compiled with option -Dptscotch
 MUMPS compiled with option -Dscotch
 This MUMPS version includes code for SAVE_RESTORE
 This MUMPS version includes code for DIST_RHS
 =================================================
L U Solver for unsymmetric matrices
Type of parallelism: Working host

 ****** ANALYSIS STEP ********

 ... Structural symmetry (in percent)=   36
 Average density of rows/columns =   14
 Scaling will be computed during analysis
Compute maximum matching (Maximum Transversal):  5
 ... JOB =  5: MAXIMIZE PRODUCT DIAGONAL AND SCALE
 ... Apply column permutation
 ... Structural symmetry (in percent)=   58
 Average density of rows/columns =   12
 Ordering based on METIS
 ELAPSED TIME SPENT IN METIS reordering  =      3.7177

Leaving analysis phase with  ...
 INFOG(1)                                       =               0
 INFOG(2)                                       =               0
 -- (20) Number of entries in factors (estim.)  =       114518451
 --  (3) Real space for factors    (estimated)  =       114518451
 --  (4) Integer space for factors (estimated)  =        11056766
 --  (5) Maximum frontal size      (estimated)  =            4280
 --  (6) Number of nodes in the tree            =          284628
 -- (32) Type of analysis effectively used      =               1
 --  (7) Ordering option effectively used       =               5
 ICNTL(6) Maximum transversal option            =               5
 ICNTL(7) Pivot order option                    =               5
 ICNTL(14) Percentage of memory relaxation      =             100
 Number of level 2 nodes                        =               0
 Number of split nodes                          =               0
 RINFOG(1) Operations during elimination (estim)= 2.010D+11

 MEMORY ESTIMATIONS ... 
 Estimations with standard Full-Rank (FR) factorization:
    Total space in MBytes, IC factorization      (INFOG(17)):        2183
    Total space in MBytes,  OOC factorization    (INFOG(27)):         754

 Elapsed time in analysis driver=       5.1528

Entering DMUMPS 5.3.5 from C interface with JOB, N, NNZ =   2      659033        5959282
      executing #MPI =      1, without OMP



****** FACTORIZATION STEP ********

 GLOBAL STATISTICS PRIOR NUMERICAL FACTORIZATION ...
 Number of working processes                =               1
 ICNTL(22) Out-of-core option               =               0
 ICNTL(35) BLR activation (eff. choice)     =               0
 ICNTL(14) Memory relaxation                =             100
 INFOG(3) Real space for factors (estimated)=       114518451
 INFOG(4) Integer space for factors (estim.)=        11056766
 Maximum frontal size (estimated)           =            4280
 Number of nodes in the tree                =          284628
 Memory allowed (MB -- 0: N/A )             =           30000
 Memory provided by user, sum of LWK_USER   =               0
 Relative threshold for pivoting, CNTL(1)   =      0.1000D-01
 Effective size of S     (based on INFO(39))=           1980130135

 Elapsed time to reformat/distribute matrix =      0.0860

 ** Memory allocated, total in Mbytes           (INFOG(19)):       16091
 ** Memory effectively used, total in Mbytes    (INFOG(22)):        1217

 Elapsed time for factorization             =      6.0571

Leaving factorization with ...
 RINFOG(2)  Operations in node assembly     = 1.934D+08
 ------(3)  Operations in node elimination  = 2.013D+11
 ICNTL (8)  Scaling effectively used        =              -2
 INFOG (9)  Real space for factors          =       114619909
 INFOG(10)  Integer space for factors       =        11059000
 INFOG(11)  Maximum front size              =            4280
 INFOG(29)  Number of entries in factors    =       114619909
 INFOG(12)  Number of off diagonal pivots   =            2050
 INFOG(13)  Number of delayed pivots        =            1117
 INFOG(14)  Number of memory compress       =               0

 Elapsed time in factorization driver=       6.1436

Entering DMUMPS 5.3.5 from C interface with JOB, N, NNZ =   3      659033        5959282
      executing #MPI =      1, without OMP



 ****** SOLVE & CHECK STEP ********

 GLOBAL STATISTICS PRIOR SOLVE PHASE ...........
 Number of right-hand-sides                    =           1
 Blocking factor for multiple rhs              =           1
 ICNTL (9)                                     =           1
  --- (10)                                     =           0
  --- (11)                                     =           0
  --- (20)                                     =           0
  --- (21)                                     =           0
  --- (30)                                     =           0
  --- (35)                                     =           0
 ** Space in MBYTES used for solve                        :     16109

 Leaving solve with ...
 Time to build/scatter RHS        =       0.013788
 Time in solution step (fwd/bwd)  =       0.556302
  .. Time in forward (fwd) step   =          0.253481
  .. Time in backward (bwd) step  =          0.302814
 Time to gather solution(cent.sol)=       0.002590
 Time to copy/scale dist. solution=       0.000000

 Elapsed time in solve driver=       0.5893
```

## pre2 matrix with 2 proc

```
Entering DMUMPS 5.3.5 from C interface with JOB, N, NNZ =   1      659033        5959282
      executing #MPI =      2, without OMP

 =================================================
 MUMPS compiled with option -Dmetis
 MUMPS compiled with option -Dparmetis
 MUMPS compiled with option -Dptscotch
 MUMPS compiled with option -Dscotch
 This MUMPS version includes code for SAVE_RESTORE
 This MUMPS version includes code for DIST_RHS
 =================================================
L U Solver for unsymmetric matrices
Type of parallelism: Working host

 ****** ANALYSIS STEP ********

Using ParMETIS for parallel ordering.
Structural symmetry is: 36%
 A root of estimated size         1762  has been selected for Scalapack.

Leaving analysis phase with  ...
 INFOG(1)                                       =               0
 INFOG(2)                                       =               0
 -- (20) Number of entries in factors (estim.)  =       291766145
 --  (3) Real space for factors    (estimated)  =       291766145
 --  (4) Integer space for factors (estimated)  =        10431530
 --  (5) Maximum frontal size      (estimated)  =            3996
 --  (6) Number of nodes in the tree            =          194556
 -- (32) Type of analysis effectively used      =               2
 --  (7) Ordering option effectively used       =               2
 ICNTL(6) Maximum transversal option            =               0
 ICNTL(7) Pivot order option                    =               5
 ICNTL(14) Percentage of memory relaxation      =             100
 Number of level 2 nodes                        =               1
 Number of split nodes                          =               0
 RINFOG(1) Operations during elimination (estim)= 2.926D+11

 MEMORY ESTIMATIONS ... 
 Estimations with standard Full-Rank (FR) factorization:
    Maximum estim. space in Mbytes, IC facto.    (INFOG(16)):        2770
    Total space in MBytes, IC factorization      (INFOG(17)):        5428
    Maximum estim. space in Mbytes, OOC facto.   (INFOG(26)):         663
    Total space in MBytes,  OOC factorization    (INFOG(27)):        1262

 Elapsed time in analysis driver=       5.7684

Entering DMUMPS 5.3.5 from C interface with JOB, N, NNZ =   2      659033        5959282
      executing #MPI =      2, without OMP



****** FACTORIZATION STEP ********

 GLOBAL STATISTICS PRIOR NUMERICAL FACTORIZATION ...
 Number of working processes                =               2
 ICNTL(22) Out-of-core option               =               0
 ICNTL(35) BLR activation (eff. choice)     =               0
 ICNTL(14) Memory relaxation                =             100
 INFOG(3) Real space for factors (estimated)=       291766145
 INFOG(4) Integer space for factors (estim.)=        10431530
 Maximum frontal size (estimated)           =            3996
 Number of nodes in the tree                =          194556
 Memory allowed (MB -- 0: N/A )             =           15000
 Memory provided by user, sum of LWK_USER   =               0
 Relative threshold for pivoting, CNTL(1)   =      0.1000D-01
 Max difference from 1 after scaling the entries for ONE-NORM (option 7/8)   = 0.12D+01
 Average Effective size of S     (based on INFO(39))=           1086575503

 Elapsed time to reformat/distribute matrix =      0.0992
 ** Memory allocated, max in Mbytes             (INFOG(18)):        8885

 ** Memory allocated, total in Mbytes           (INFOG(19)):       17714
 ** Memory effectively used, max in  Mbytes     (INFOG(21)):        2658
 ** Memory effectively used, total in Mbytes    (INFOG(22)):        5287

 Elapsed time for factorization             =     26.6280

Leaving factorization with ...
 RINFOG(2)  Operations in node assembly     = 6.956D+08
 ------(3)  Operations in node elimination  = 1.195D+12
 ICNTL (8)  Scaling effectively used        =               7
 INFOG (9)  Real space for factors          =       566081787
 INFOG(10)  Integer space for factors       =        11129371
 INFOG(11)  Maximum front size              =            7307
 INFOG(29)  Number of entries in factors    =       566081787
 INFOG(12)  Number of off diagonal pivots   =          421119
 INFOG(13)  Number of delayed pivots        =          348700
 INFOG(14)  Number of memory compress       =               0

 Elapsed time in factorization driver=      26.8028

Entering DMUMPS 5.3.5 from C interface with JOB, N, NNZ =   3      659033        5959282
      executing #MPI =      2, without OMP



 ****** SOLVE & CHECK STEP ********

 GLOBAL STATISTICS PRIOR SOLVE PHASE ...........
 Number of right-hand-sides                    =           1
 Blocking factor for multiple rhs              =           1
 ICNTL (9)                                     =           1
  --- (10)                                     =           0
  --- (11)                                     =           0
  --- (20)                                     =           0
  --- (21)                                     =           0
  --- (30)                                     =           0
  --- (35)                                     =           0
 ** Rank of processor needing largest memory in solve     :         0
 ** Space in MBYTES used by this processor for solve      :      8878
 ** Avg. Space in MBYTES per working proc during solve    :      8842

 Leaving solve with ...
 Time to build/scatter RHS        =       0.014730
 Time in solution step (fwd/bwd)  =       0.574957
  .. Time in forward (fwd) step   =          0.278542
  .. Time in ScaLAPACK root       =          0.030688
  .. Time in backward (bwd) step  =          0.265720
 Time to gather solution(cent.sol)=       0.036826
 Time to copy/scale dist. solution=       0.000000

 Elapsed time in solve driver=       0.6428
```

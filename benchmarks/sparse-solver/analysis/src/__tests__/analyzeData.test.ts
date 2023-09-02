import { analyzeData } from '../analyzeData';
import { IReport } from '../types';
import { NS_PER_SECOND } from '../constants';

describe('analyzeData', () => {
  const mumps_inline_1_metis_open_mpi1_omp1: IReport = {
    Platform: 'laclib',
    SolverKind: 'mumps',
    MatrixName: 'inline_1',
    Ordering: 'metis',
    MpiSize: 1,
    OmpNumThreads: 1,
    Symmetric: true,
    NumberOfRows: 503712,
    NumberOfCols: 503712,
    NumberOfNonZeros: 18660027,
    StepReadMatrix: {
      ElapsedTimeNanoseconds: 6417059646,
      ElapsedTimeString: '6.41706s',
      MemoryBytes: 632238080,
      MemoryMiB: '602',
    },
    StepAnalyze: {
      ElapsedTimeNanoseconds: 3434966495,
      ElapsedTimeString: '3.43497s',
      MemoryBytes: 773402624,
      MemoryMiB: '737',
    },
    StepFactorize: {
      ElapsedTimeNanoseconds: 6000000000, // <<<<<<<<<<<<<<<<<<<<<
      ElapsedTimeString: '6.0s',
      MemoryBytes: 17622884352,
      MemoryMiB: '16,806',
    },
    StepSolve: {
      ElapsedTimeNanoseconds: 386839712,
      ElapsedTimeString: '386.84ms',
      MemoryBytes: 17622884352,
      MemoryMiB: '16,806',
    },
    TimeSolverNanoseconds: 10284253978,
    TimeSolverString: '10.2843s',
    Stats: {
      NormInfA: 114603634.398607,
      NormInfAx: 1.00000032037497,
      NormInfDiff: 4.17259116147761e-7,
      RelativeError: 3.64088900580227e-15,
      ElapsedTimeNanoseconds: 58059877,
      ElapsedTimeString: '58.0599ms',
    },
  };

  const mumps_inline_1_metis_open_mpi1_omp2: IReport = {
    Platform: 'laclib',
    SolverKind: 'mumps',
    MatrixName: 'inline_1',
    Ordering: 'metis',
    MpiSize: 1,
    OmpNumThreads: 2,
    Symmetric: true,
    NumberOfRows: 503712,
    NumberOfCols: 503712,
    NumberOfNonZeros: 18660027,
    StepReadMatrix: {
      ElapsedTimeNanoseconds: 6377910490,
      ElapsedTimeString: '6.37791s',
      MemoryBytes: 632238080,
      MemoryMiB: '602',
    },
    StepAnalyze: {
      ElapsedTimeNanoseconds: 3456783257,
      ElapsedTimeString: '3.45678s',
      MemoryBytes: 773156864,
      MemoryMiB: '737',
    },
    StepFactorize: {
      ElapsedTimeNanoseconds: 18000000000, // <<<<<<<<<<<<<<<<<<<<<
      ElapsedTimeString: '18.0s',
      MemoryBytes: 17631494144,
      MemoryMiB: '16,814',
    },
    StepSolve: {
      ElapsedTimeNanoseconds: 1061314983,
      ElapsedTimeString: '1.06131s',
      MemoryBytes: 17631494144,
      MemoryMiB: '16,814',
    },
    TimeSolverNanoseconds: 22816722829,
    TimeSolverString: '22.8167s',
    Stats: {
      NormInfA: 114603634.398607,
      NormInfAx: 1.00000031292439,
      NormInfDiff: 3.12924385070801e-7,
      RelativeError: 2.73049265830361e-15,
      ElapsedTimeNanoseconds: 85679818,
      ElapsedTimeString: '85.6798ms',
    },
  };

  const mumps_inline_1_metis_open_mpi1_omp3: IReport = {
    Platform: 'laclib',
    SolverKind: 'mumps',
    MatrixName: 'inline_1',
    Ordering: 'metis',
    MpiSize: 1,
    OmpNumThreads: 3,
    Symmetric: true,
    NumberOfRows: 503712,
    NumberOfCols: 503712,
    NumberOfNonZeros: 18660027,
    StepReadMatrix: {
      ElapsedTimeNanoseconds: 6399934692,
      ElapsedTimeString: '6.39993s',
      MemoryBytes: 632238080,
      MemoryMiB: '602',
    },
    StepAnalyze: {
      ElapsedTimeNanoseconds: 3476273181,
      ElapsedTimeString: '3.47627s',
      MemoryBytes: 816574464,
      MemoryMiB: '778',
    },
    StepFactorize: {
      ElapsedTimeNanoseconds: 16000000000, // <<<<<<<<<<<<<<<<<<<<<
      ElapsedTimeString: '16.0s',
      MemoryBytes: 17683300352,
      MemoryMiB: '16,864',
    },
    StepSolve: {
      ElapsedTimeNanoseconds: 764809307,
      ElapsedTimeString: '764.809ms',
      MemoryBytes: 17683300352,
      MemoryMiB: '16,864',
    },
    TimeSolverNanoseconds: 20920332239,
    TimeSolverString: '20.9203s',
    Stats: {
      NormInfA: 114603634.398607,
      NormInfAx: 1.00000034703407,
      NormInfDiff: 3.47034074366093e-7,
      RelativeError: 3.02812448452495e-15,
      ElapsedTimeNanoseconds: 89464172,
      ElapsedTimeString: '89.4642ms',
    },
  };

  const mumps_inline_1_metis_open_mpi1_omp4: IReport = {
    Platform: 'laclib',
    SolverKind: 'mumps',
    MatrixName: 'inline_1',
    Ordering: 'metis',
    MpiSize: 1,
    OmpNumThreads: 4,
    Symmetric: true,
    NumberOfRows: 503712,
    NumberOfCols: 503712,
    NumberOfNonZeros: 18660027,
    StepReadMatrix: {
      ElapsedTimeNanoseconds: 6398463985,
      ElapsedTimeString: '6.39846s',
      MemoryBytes: 632238080,
      MemoryMiB: '602',
    },
    StepAnalyze: {
      ElapsedTimeNanoseconds: 3507007836,
      ElapsedTimeString: '3.50701s',
      MemoryBytes: 859078656,
      MemoryMiB: '819',
    },
    StepFactorize: {
      ElapsedTimeNanoseconds: 19000000000, // <<<<<<<<<<<<<<<<<<<<<
      ElapsedTimeString: '19.0s',
      MemoryBytes: 17734193152,
      MemoryMiB: '16,912',
    },
    StepSolve: {
      ElapsedTimeNanoseconds: 1104188154,
      ElapsedTimeString: '1.10419s',
      MemoryBytes: 17734193152,
      MemoryMiB: '16,912',
    },
    TimeSolverNanoseconds: 23665107331,
    TimeSolverString: '23.6651s',
    Stats: {
      NormInfA: 114603634.398607,
      NormInfAx: 1.00000025611371,
      NormInfDiff: 3.00854026136221e-7,
      RelativeError: 2.62517000520804e-15,
      ElapsedTimeNanoseconds: 108995358,
      ElapsedTimeString: '108.995ms',
    },
  };

  it('should compute speedup', () => {
    const reports: IReport[] = [
      mumps_inline_1_metis_open_mpi1_omp1,
      mumps_inline_1_metis_open_mpi1_omp2,
      mumps_inline_1_metis_open_mpi1_omp3,
      mumps_inline_1_metis_open_mpi1_omp4,
    ];
    const res = analyzeData(reports);
    expect(res.fac).toEqual({
      firstNanoseconds: 6 * NS_PER_SECOND,
      lastNanoseconds: 19 * NS_PER_SECOND,
      maxDeltaNanoseconds: 12 * NS_PER_SECOND,
      deltaNanoseconds: [0, 12 * NS_PER_SECOND, -2 * NS_PER_SECOND, 3 * NS_PER_SECOND],
      speedup: [1.0, 6.0 / 18.0, 6.0 / 16.0, 6.0 / 19.0],
    });
  });
});

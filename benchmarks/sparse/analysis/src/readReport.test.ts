import { readReport } from './readReport';

describe('readReport', () => {
  it('reads bfwb62', () => {
    const rpt = readReport('bfwb62');
    expect(rpt).toEqual({
      Platform: 'laclib',
      SolverKind: 'mumps',
      MatrixName: 'bfwb62',
      Ordering: 'metis',
      MpiSize: 1,
      Symmetric: true,
      NumberOfRows: 62,
      NumberOfCols: 62,
      NumberOfNonZeros: 202,
      StepReadMatrix: {
        ElapsedTimeNanoseconds: 300320,
        ElapsedTimeString: '300.32µs',
        MemoryBytes: 333336576,
        MemoryMiB: '317',
      },
      StepAnalyze: {
        ElapsedTimeNanoseconds: 1808093,
        ElapsedTimeString: '1.80809ms',
        MemoryBytes: 333516800,
        MemoryMiB: '318',
      },
      StepFactorize: {
        ElapsedTimeNanoseconds: 1219917,
        ElapsedTimeString: '1.21992ms',
        MemoryBytes: 15366782976,
        MemoryMiB: '14,654',
      },
      StepSolve: {
        ElapsedTimeNanoseconds: 792976,
        ElapsedTimeString: '792.976µs',
        MemoryBytes: 15366782976,
        MemoryMiB: '14,654',
      },
      TimeSolverNanoseconds: 3313270,
      TimeSolverString: '3.31327ms',
      Stats: {
        NormInfA: 0.0001,
        NormInfAx: 1,
        NormInfDiff: 6.66133814775094e-16,
        RelativeError: 6.66067208054288e-16,
        ElapsedTimeNanoseconds: 6440,
        ElapsedTimeString: '6.44µs',
      },
    });
  });

  it('fails due to wrong matrixName', () => {
    expect(() => {
      readReport('nada');
    }).toThrowError(
      "ENOENT: no such file or directory, open '../results/mumps_nada_metis_np1.json'",
    );
  });
});

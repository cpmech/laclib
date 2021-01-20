export interface ITimeAndMemoryFull {
  ElapsedTimeNanoseconds: number;
  ElapsedTimeString: string;
  MemoryBytes: number;
  MemoryMiB: string;
}

export interface IStats {
  NormInfA: number;
  NormInfAx: number;
  NormInfDiff: number;
  RelativeError: number;
  ElapsedTimeNanoseconds: number;
  ElapsedTimeString: string;
}

export interface IReport {
  Platform: string;
  SolverKind: string;
  MatrixName: string;
  Ordering: string;
  MpiSize: number;
  OmpNumThreads: number;
  Symmetric: boolean;
  NumberOfRows: number;
  NumberOfCols: number;
  NumberOfNonZeros: number;
  StepReadMatrix: ITimeAndMemoryFull;
  StepAnalyze: ITimeAndMemoryFull;
  StepFactorize: ITimeAndMemoryFull;
  StepSolve: ITimeAndMemoryFull;
  TimeSolverNanoseconds: number;
  TimeSolverString: string;
  Stats: IStats;
}

export const zeroTimeAndMemoryFull = (): ITimeAndMemoryFull => ({
  ElapsedTimeNanoseconds: 0,
  ElapsedTimeString: '',
  MemoryBytes: 0,
  MemoryMiB: '',
});

export const zeroStats = (): IStats => ({
  NormInfA: 0,
  NormInfAx: 0,
  NormInfDiff: 0,
  RelativeError: 0,
  ElapsedTimeNanoseconds: 0,
  ElapsedTimeString: '',
});

export const zeroReport = (): IReport => ({
  Platform: '',
  SolverKind: '',
  MatrixName: '',
  Ordering: '',
  MpiSize: 0,
  OmpNumThreads: 0,
  Symmetric: false,
  NumberOfRows: 0,
  NumberOfCols: 0,
  NumberOfNonZeros: 0,
  StepReadMatrix: zeroTimeAndMemoryFull(),
  StepAnalyze: zeroTimeAndMemoryFull(),
  StepFactorize: zeroTimeAndMemoryFull(),
  StepSolve: zeroTimeAndMemoryFull(),
  TimeSolverNanoseconds: 0,
  TimeSolverString: '',
  Stats: zeroStats(),
});

export interface IColumns {
  ana: string;
  fac: string;
  sol: string;
  tot: string;
  normAx: string;
  relErr: string;
}

export type IReportSet = {
  [name: string]: IReport[];
};

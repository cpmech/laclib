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
  link?: string;
}

export interface IAnalysis {
  fac: {
    firstNanoseconds: number;
    lastNanoseconds: number;
    maxDeltaNanoseconds: number;
    deltaNanoseconds: number[];
    speedup: number[];
  };
}

export interface IReportsAndAnalysis {
  reports: IReport[]; // e.g.: "intel" => [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
  analysis?: IAnalysis;
}

export type IReportSet = {
  [name: string]: IReportsAndAnalysis;
};

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

export type PlatToolset = 'open' | 'intel';

export type PlatOption = 'seq_omp#' | 'mpi1_omp#' | 'mpi#' | 'mpi#_omp1' | 'mpi#_omp#';

export type TableField = 'Analyze' | 'Factorize' | 'Solve' | 'Total' | 'Norm(A.x)' | 'Rel Error';

export type IHtmlColData = {
  [option in TableField]: string;
};

export const DescribePlatOption: { [key in PlatOption]: string } = {
  'seq_omp#': 'sequential (no mpi) with varying number of OpenMP threads',
  'mpi1_omp#': 'compiled with MPI but with varying number of OpenMP threads (mpirun -np 1)',
  'mpi#': 'varying number of MPI procs; without OpenMP',
  'mpi#_omp1': 'varying number of MPI procs, but compiled with OpenMP (ignored)',
  'mpi#_omp#': '1 and 2 MPI procs combined with 1 and 2 OpenMP threads (1-1, 1-2, 2-1, 2-2)',
};

export interface IHtmlStyles {
  table: string;
  tabHeader: string;
  tabLHeader: string;
  tabData: string;
  tabDataLabel: string;
}

export const defaultHtmlStyles = (
  tableBorderColor = '#979797',
  tablePadding = '5px',
): IHtmlStyles => {
  return {
    table: ` style="border: 1px solid ${tableBorderColor}; border-collapse: collapse;"`,
    tabHeader: ` style="border: 1px solid ${tableBorderColor}; border-collapse: collapse; text-align: center; padding: ${tablePadding};"`,
    tabLHeader: ` style="border: 1px solid ${tableBorderColor}; border-collapse: collapse; text-align: right; padding: ${tablePadding};"`,
    tabData: ` style="border: 1px solid ${tableBorderColor}; border-collapse: collapse; text-align: center; padding: ${tablePadding};"`,
    tabDataLabel: ` style="border: 1px solid ${tableBorderColor}; border-collapse: collapse; text-align: right; padding: ${tablePadding};"`,
  };
};

import { camelize } from '@cpmech/basic';
import { readReport } from './readReport';
import { INewReport } from './typesNewReport';

async function run() {
  const args = process.argv.slice(2);
  const fnkey = args.length > 0 ? args[0] : 'mumps_bfwb62_metis_open_seq';
  const subDir = args.length > 1 ? args[1] : 'latest';

  let oldRpt = readReport(fnkey, subDir);
  let newRpt: INewReport = {
    platform: oldRpt.Platform,
    matrixName: oldRpt.MatrixName,
    read: {
      timeReadNs: oldRpt.StepReadMatrix.ElapsedTimeNanoseconds,
      timeReadStr: oldRpt.StepReadMatrix.ElapsedTimeString,
    },
    triplet: {
      nrow: oldRpt.NumberOfRows,
      ncol: oldRpt.NumberOfCols,
      pos: oldRpt.NumberOfNonZeros,
      max: oldRpt.NumberOfNonZeros,
      symPart: oldRpt.Symmetric,
      symFull: false,
    },
    solver: {
      solverKind: 'MMP',
      symmetry: oldRpt.Symmetric ? 'General' : 'No',
      ordering: camelize(oldRpt.Ordering, true),
      scaling: 'Auto',
      pctIncWorkspace: 120,
      maxWorkMemory: 30000,
      openmpNumThreads: oldRpt.OmpNumThreads,
      doneInitialize: true,
      doneFactorize: true,
      ndim: oldRpt.NumberOfRows,
      timeInitNs: oldRpt.StepAnalyze.ElapsedTimeNanoseconds,
      timeFactNs: oldRpt.StepFactorize.ElapsedTimeNanoseconds,
      timeSolveNs: oldRpt.StepSolve.ElapsedTimeNanoseconds,
      timeTotalNs: oldRpt.TimeSolverNanoseconds,
      timeInitStr: oldRpt.StepAnalyze.ElapsedTimeString,
      timeFactStr: oldRpt.StepFactorize.ElapsedTimeString,
      timeSolveStr: oldRpt.StepSolve.ElapsedTimeString,
      timeTotalStr: oldRpt.TimeSolverString,
    },
    verify: {
      maxAbsA: oldRpt.Stats.NormInfA,
      maxAbsAx: oldRpt.Stats.NormInfAx,
      maxAbsDiff: oldRpt.Stats.NormInfDiff,
      relativeError: oldRpt.Stats.RelativeError,
      timeCheckNs: oldRpt.Stats.ElapsedTimeNanoseconds,
      timeCheckStr: oldRpt.Stats.ElapsedTimeString,
    },
  };

  console.log(newRpt);
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();

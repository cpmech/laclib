import { v4 } from 'uuid';
import { camelize } from '@cpmech/basic';
import { maybeWriteFile } from '@cpmech/basic-sys';
import { readReport } from './readReport';
import { INewReport } from './typesNewReport';

const convert = (blasLib: string, matrixName: string, ompNt: number) => {
  const suffix = ompNt == 0 ? '' : `_omp${ompNt}`;
  const fnkey = `mumps_${matrixName}_metis_${blasLib}_seq${suffix}`;

  const oldRpt = readReport(fnkey, blasLib);

  const newRpt: INewReport = {
    platform: oldRpt.Platform,
    blasLib: blasLib == 'intel' ? 'IntelMKL' : 'OpenBLAS',
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

  const filepath = `/tmp/laclib/${matrixName}/${v4()}.json`;
  maybeWriteFile(true, filepath, () => JSON.stringify(newRpt, null, 2) + '\n');
  console.log(filepath);
};

async function run() {
  const args = process.argv.slice(2);
  if (args.length != 2) {
    console.log('Usage:');
    console.log();
    console.log(`    basename  BLASLIB MATRIX_NAME OMP_NT`);
    console.log();
    console.log('Where:');
    console.log();
    console.log('  BLASLIB     -- {intel,open,latest}');
    console.log('  MATRIX_NAME -- e.g., pre2');
    console.log();
    return;
  }

  const blasLib = args[0];
  const matrixName = args[1];

  for (let ompNt = 0; ompNt < 5; ompNt++) {
    convert(blasLib, matrixName, ompNt);
  }
}

(async () => {
  try {
    await run();
  } catch (e) {
    console.log(e);
  }
})();

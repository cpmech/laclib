import fs from 'fs';
import { any2type } from '@cpmech/js2ts';
import { IReport, reportOptional, zeroReport } from './report';

const RESDIR = '../results';

export const readReport = (
  matrixName: string,
  mpiSize: number = 1,
  ompNumThreads: number = 0,
  solverKind: string = 'mumps',
  ordering: string = 'metis',
  intel: boolean = false,
): IReport => {
  const pfx = intel ? 'intel_' : '';
  const omp = ompNumThreads > 0 ? `_omp${ompNumThreads}` : '';
  const fnkey = `${pfx}${solverKind}_${matrixName}_${ordering}_np${mpiSize}${omp}`;
  const dataJson = fs.readFileSync(`${RESDIR}/${fnkey}.json`, 'utf8');
  const dataObject = JSON.parse(dataJson);
  const report = any2type(zeroReport(), dataObject, true, reportOptional);
  if (!report) {
    throw 'cannot parse report';
  }
  return report;
};

import fs from 'fs';
import { any2type } from '@cpmech/js2ts';
import { IReport, zeroReport } from './report';

const RESDIR = '../results';

export const readReport = (fnkey: string, intel = false): IReport => {
  const x = intel ? '/intel' : '/open';
  const dataJson = fs.readFileSync(`${RESDIR}${x}/${fnkey}.json`, 'utf8');
  const dataObject = JSON.parse(dataJson);
  const report = any2type(zeroReport(), dataObject);
  if (!report) {
    throw 'cannot parse report';
  }
  return report;
};

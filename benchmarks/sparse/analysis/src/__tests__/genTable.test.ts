import { genTable } from '../genTable';
import { IReport, zeroReport } from '../types';

describe('genTable', () => {
  it('generates default table', () => {
    const r = zeroReport();
    r.StepAnalyze.ElapsedTimeString = '1s';
    r.StepFactorize.ElapsedTimeString = '2s';
    r.StepSolve.ElapsedTimeString = '3s';
    r.TimeSolverString = '6s';
    const reports: IReport[] = [r, r, r, r];
    const table = genTable('mytable', reports);
    expect(table).toMatchSnapshot();
  });

  it('generates OMP table', () => {
    const r = zeroReport();
    r.StepAnalyze.ElapsedTimeString = '1s';
    r.StepFactorize.ElapsedTimeString = '2s';
    r.StepSolve.ElapsedTimeString = '3s';
    r.TimeSolverString = '6s';
    const reports: IReport[] = [r, r, r, r];
    const table = genTable('mytable', reports, true);
    expect(table).toMatchSnapshot();
  });
});

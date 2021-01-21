import { IReport } from './types';

interface IAnalysis {
  fac: {
    firstNanoseconds: number;
    lastNanoseconds: number;
    maxDeltaNanoseconds: number;
    deltaNanoseconds: number[];
    speedup: number[];
  };
}

export const analyzeData = (data: IReport[]) => {
  return data.reduce((acc, curr) => {
    // data
    const data = curr.StepFactorize;

    // first
    if (!acc.fac) {
      return {
        fac: {
          firstNanoseconds: data.ElapsedTimeNanoseconds,
          lastNanoseconds: data.ElapsedTimeNanoseconds,
          maxDeltaNanoseconds: 0,
          deltaNanoseconds: [0],
          speedup: [1.0],
        },
      };
    }

    // next
    const deltaNanoseconds = data.ElapsedTimeNanoseconds - acc.fac.lastNanoseconds;
    const speedup = acc.fac.firstNanoseconds / data.ElapsedTimeNanoseconds;
    acc.fac.lastNanoseconds = data.ElapsedTimeNanoseconds;
    acc.fac.maxDeltaNanoseconds = Math.max(acc.fac.maxDeltaNanoseconds, deltaNanoseconds);
    acc.fac.deltaNanoseconds.push(deltaNanoseconds);
    acc.fac.speedup.push(speedup);

    // results
    return acc;
  }, {} as IAnalysis);
};

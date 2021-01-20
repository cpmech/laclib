import { IColumns } from './types';
import { styTabLHeader } from './htmlStyles';

export const genRows = (columns: IColumns[]): string => {
  const n = columns.length;

  const tr0 = `\n  <tr>\n`;
  const trx = `\n  </tr>`;

  const d = (i: number, label: string, data: string) =>
    i === 0
      ? `    <th style="${styTabLHeader}" rowspan="${n}">${label}</th>\n    ${data}`
      : `    ${data}`;

  const ana = columns.map((c, i) => `${tr0}${d(i, 'Analyze', c.ana)}${trx}`);
  const fac = columns.map((c, i) => `${tr0}${d(i, 'Factorize', c.fac)}${trx}`);
  const sol = columns.map((c, i) => `${tr0}${d(i, 'Solve', c.sol)}${trx}`);
  const tot = columns.map((c, i) => `${tr0}${d(i, 'Total', c.tot)}${trx}`);
  const nax = columns.map((c, i) => `${tr0}${d(i, 'Linf(A*x)', c.normAx)}${trx}`);
  const rer = columns.map((c, i) => `${tr0}${d(i, 'Rel Error', c.relErr)}${trx}`);

  const s = '';
  return ana.join(s) + fac.join(s) + sol.join(s) + tot.join(s) + nax.join(s) + rer.join(s);
};

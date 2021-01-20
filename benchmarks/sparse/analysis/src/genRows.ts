import { IColumns } from './types';
import { styTabLHeader } from './htmlStyles';

export const genRows = (columns: IColumns[], withLinfAx = false): string => {
  const n = columns.length;

  const tr0 = `\n  <tr>\n`;
  const trx = `\n  </tr>`;

  const rowspan = n > 1 ? ` rowspan="${n}"` : '';

  const d = (i: number, label: string, cols: string) =>
    i === 0
      ? `    <th style="${styTabLHeader}"${rowspan}>${label}</th>\n    ${cols}`
      : `    ${cols}`;

  const ana = columns.map((c, i) => `${tr0}${d(i, 'Analyze', c.ana)}${trx}`);
  const fac = columns.map((c, i) => `${tr0}${d(i, 'Factorize', c.fac)}${trx}`);
  const sol = columns.map((c, i) => `${tr0}${d(i, 'Solve', c.sol)}${trx}`);
  const tot = columns.map((c, i) => `${tr0}${d(i, 'Total', c.tot)}${trx}`);
  const rer = columns.map((c, i) => `${tr0}${d(i, 'Rel Error', c.relErr)}${trx}`);

  let lines = ana.join('') + fac.join('') + sol.join('') + tot.join('');
  if (withLinfAx) {
    const nax = columns.map((c, i) => `${tr0}${d(i, 'Linf(A.x)', c.normAx)}${trx}`);
    lines += nax.join('');
  }
  lines += rer.join('');

  return lines;
};

import { IHtmlColData } from './types';
import { styTabLHeader } from './htmlStyles';

export const genHtmlTableRows = (data: IHtmlColData[], withLinfAx = false): string => {
  const numOfLabels = data.length;

  const tr0 = `\n  <tr>\n`;
  const trx = `\n  </tr>`;

  const rowspan = numOfLabels > 1 ? ` rowspan="${numOfLabels}"` : '';

  const d = (i: number, label: string, cols: string) =>
    i === 0
      ? `    <th style="${styTabLHeader}"${rowspan}>${label}</th>\n    ${cols}`
      : `    ${cols}`;

  const ana = data.map((c, i) => `${tr0}${d(i, 'Analyze', c.ana)}${trx}`);
  const fac = data.map((c, i) => `${tr0}${d(i, 'Factorize', c.fac)}${trx}`);
  const sol = data.map((c, i) => `${tr0}${d(i, 'Solve', c.sol)}${trx}`);
  const tot = data.map((c, i) => `${tr0}${d(i, 'Total', c.tot)}${trx}`);
  const rer = data.map((c, i) => `${tr0}${d(i, 'Rel Error', c.relErr)}${trx}`);

  let lines = ana.join('') + fac.join('') + sol.join('') + tot.join('');
  if (withLinfAx) {
    const nax = data.map((c, i) => `${tr0}${d(i, 'Linf(A.x)', c.normAx)}${trx}`);
    lines += nax.join('');
  }
  lines += rer.join('');

  return lines;
};

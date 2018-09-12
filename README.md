# ntHash bug?

[![Binder](https://mybinder.org/badge.svg)](https://mybinder.org/v2/gh/luizirber/nthash_bug/master?filepath=analysis.ipynb)

Analysis of a possible bug in the ntHash code (or maybe I'm missing something
obvious in my implementations...)

I recommend clicking on the "Launch binder" button above and exploring the
notebook interactively (GitHub doesn't keep some of the formatting).
Alternatively, use [nbviewer](https://nbviewer.jupyter.org/github/luizirber/nthash_bug/blob/master/analysis.ipynb) (which preserves the formatting).

UPDATE: I opened an [issue](https://github.com/bcgsc/ntHash/issues/7) and seems
like the current `master` version is the culprit (more specifically
[57af16a](https://github.com/bcgsc/ntHash/tree/57af16a972a553ecccea0cda25af85ac1f96a94b/)).
Reverting back to the [`1.0.4` release](https://github.com/bcgsc/ntHash/releases/tag/1.0.4)
fixes the problem. There is a new section at the end of the notebook with more details.

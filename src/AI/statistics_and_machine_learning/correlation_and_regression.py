#!/usr/bin/python

import numpy as np
import scipy.stats

physics_scores = [15,12,8,8,7,7,7,6,5,3]
history_scores = [10,25,17,11,13,17,20,13,9,15]
physics_std = np.std(physics_scores)
history_std = np.std(history_scores)
np.set_printoptions(precision=3)
pearsonr = np.round(scipy.stats.pearsonr(physics_scores, history_scores),3)
pearsonr[0]


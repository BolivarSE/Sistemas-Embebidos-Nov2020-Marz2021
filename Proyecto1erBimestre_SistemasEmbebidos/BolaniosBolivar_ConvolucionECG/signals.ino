
double ecg[100]=
{
402, 386, 386, 382, 379, 397, 396, 416, 431, 442,
470, 481, 514, 530, 535, 553, 546, 556, 552, 541,
545, 524, 520, 505, 487, 488, 466, 467, 459, 449,
457, 443, 453, 450, 444, 456, 443, 454, 452, 450,
464, 454, 466, 466, 464, 477, 468, 480, 480, 477,
489, 479, 491, 487, 483, 493, 484, 498, 499, 498,
516, 513, 544, 578, 627, 700, 751, 816, 854, 871,
887, 863, 846, 802, 749, 705, 638, 593, 542, 495,
470, 431, 422, 408, 396, 404, 395, 413, 418, 424,
447, 449, 475, 486, 496, 518, 515, 534, 533, 530,
};
//Filtro pasabajos de 2KHz



double Impulse_response[21] = {
  -0.02010411882885732,
  -0.05842798004352509,
  -0.061178403647821976,
  -0.010939393385338943,
  0.05125096443534972,
  0.033220867678947885,
  -0.05655276971833928,
  -0.08565500737264514,
  0.0633795996605449,
  0.310854403656636,
  0.4344309124179415,
  0.310854403656636,
  0.0633795996605449,
  -0.08565500737264514,
  -0.05655276971833928,
  0.033220867678947885,
  0.05125096443534972,
  -0.010939393385338943,
  -0.061178403647821976,
  -0.05842798004352509,
  -0.02010411882885732
};
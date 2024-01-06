void updateTable() {
  for (int i = 0; i < samples; i++) {
    f = 2048 + (vol * sine[i]);
    secondaryArray[2 * i] = highByte(f);
    secondaryArray[2 * i + 1] = lowByte(f);
  }
}

void createTable() {
  for (int i = 0; i < samples; i++) {                                  //"for" loop iterates over the number of empty samples available
    theta = 6.28 * float(i) / float(samples);                          //Calculate the radian in each iteration
    sine[i] =  2048 * (sin(theta));                                    //compute the sine of theta and store the value in the sine table
  }
  updateTable();
}

void configLightTimer() {
  Timer1.pause();
  Timer1.setPrescaleFactor(10);
  Timer1.setOverflow(250);
  Timer1.refresh();
  Timer1.resume();
}

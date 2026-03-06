unsigned long long bpf_main(int *mem) {
  int hash = 0;
  for (int i = 1; i <= mem[0]; i++) {
    int val = 0;
    // Mappings are completely randomly generated
    switch (mem[i]) {
    case 0: {
      val = 56;
      break;
    }
    case 1: {
      val = 43;
      break;
    }
    case 2: {
      val = 57;
      break;
    }
    case 3: {
      val = 28;
      break;
    }
    case 4: {
      val = 14;
      break;
    }
    case 5: {
      val = 61;
      break;
    }
    case 6: {
      val = 10;
      break;
    }
    case 7: {
      val = 58;
      break;
    }
    case 8: {
      val = 2;
      break;
    }
    case 9: {
      val = 63;
      break;
    }
    case 10: {
      val = 49;
      break;
    }
    case 11: {
      val = 36;
      break;
    }
    case 12: {
      val = 19;
      break;
    }
    case 13: {
      val = 42;
      break;
    }
    case 14: {
      val = 37;
      break;
    }
    case 15: {
      val = 46;
      break;
    }
    case 16: {
      val = 34;
      break;
    }
    case 17: {
      val = 62;
      break;
    }
    case 18: {
      val = 47;
      break;
    }
    case 19: {
      val = 6;
      break;
    }
    case 20: {
      val = 29;
      break;
    }
    case 21: {
      val = 21;
      break;
    }
    case 22: {
      val = 15;
      break;
    }
    case 23: {
      val = 40;
      break;
    }
    case 24: {
      val = 38;
      break;
    }
    case 25: {
      val = 26;
      break;
    }
    case 26: {
      val = 17;
      break;
    }
    case 27: {
      val = 41;
      break;
    }
    case 28: {
      val = 33;
      break;
    }
    case 29: {
      val = 31;
      break;
    }
    case 30: {
      val = 23;
      break;
    }
    case 31: {
      val = 52;
      break;
    }
    case 32: {
      val = 25;
      break;
    }
    case 33: {
      val = 39;
      break;
    }
    case 34: {
      val = 11;
      break;
    }
    case 35: {
      val = 27;
      break;
    }
    case 36: {
      val = 53;
      break;
    }
    case 37: {
      val = 4;
      break;
    }
    case 38: {
      val = 24;
      break;
    }
    case 39: {
      val = 48;
      break;
    }
    case 40: {
      val = 32;
      break;
    }
    case 41: {
      val = 50;
      break;
    }
    case 42: {
      val = 7;
      break;
    }
    case 43: {
      val = 35;
      break;
    }
    case 44: {
      val = 8;
      break;
    }
    case 45: {
      val = 44;
      break;
    }
    case 46: {
      val = 51;
      break;
    }
    case 47: {
      val = 59;
      break;
    }
    case 48: {
      val = 45;
      break;
    }
    case 49: {
      val = 0;
      break;
    }
    case 50: {
      val = 9;
      break;
    }
    case 51: {
      val = 3;
      break;
    }
    case 52: {
      val = 13;
      break;
    }
    case 53: {
      val = 20;
      break;
    }
    case 54: {
      val = 30;
      break;
    }
    case 55: {
      val = 18;
      break;
    }
    case 56: {
      val = 1;
      break;
    }
    case 57: {
      val = 54;
      break;
    }
    case 58: {
      val = 22;
      break;
    }
    case 59: {
      val = 16;
      break;
    }
    case 60: {
      val = 60;
      break;
    }
    case 61: {
      val = 5;
      break;
    }
    case 62: {
      val = 12;
      break;
    }
    case 63: {
      val = 55;
      break;
    }
    default: val=114514;
    }
    hash ^= val;
  }
  return hash;
}

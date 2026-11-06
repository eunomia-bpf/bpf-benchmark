import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
import negative
negative.build('arm64',Path(sys.argv[1]),names=['scalar_vector_load_clear_high'])

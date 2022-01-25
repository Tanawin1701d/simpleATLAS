from m5.params import *
from m5.SimObject import SimObject

class ATLAS_STRUCTURE(SimObject):
    type = 'ATLAS_STRUCTURE'
    cxx_header = "learning_gem5/Atlas_structure.hh"
    cxx_class = 'gem5::memory::ATLAS_STRUCTURE'
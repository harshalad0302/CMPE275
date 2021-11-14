import datetime
import sys
import time
class Kmer:

     def __init__(self, len_str):
          self.len_str = len_str
          self.opt = "ACGT"
          self.s = ""
          self.s_last = ""

     def convert(self, c):
          if (c == 'A'):
               return 'C'
          if (c == 'C'):
               return 'G'
          if (c == 'G'):
               return 'T'
          if (c == 'T'):
               return 'A'

     def calculate_kmer(self):

          for i in range(self.len_str):
               self.s += self.opt[0]

          for i in range(self.len_str):
               self.s_last += self.opt[-1]

          counter = 1
          while (self.s != self.s_last):
               counter += 1
               # You can uncomment the next line to see all k-mers.
               # print(self.s)
               change_next = True
               for i in range(self.len_str):
                    if (change_next):
                         if (self.s[i] == self.opt[-1]):
                              self.s = self.s[:i] + \
                                  self.convert(self.s[i]) + self.s[i + 1:]
                              change_next = True
                         else:
                              self.s = self.s[:i] + \
                                  self.convert(self.s[i]) + self.s[i + 1:]
                              break

          # You can uncomment the next line to see all k-mers.
          # print(s)
          print("Number of generated k-mers: {}".format(counter))
          print("Finish!")

print("Generating ", sys.argv[1]," kmers")
start = time.time()

kmer = Kmer(int(sys.argv[1]))
kmer.calculate_kmer()

end = time.time()

diff = end - start
print(diff, "seconds")

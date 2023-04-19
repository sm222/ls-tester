#!/bin/python

import os

def main():
    os.system('make -C $(pwd)/tester')
    os.system('reset')
    os.system('tester/ls_tester.out')
#    os.system('rm tester/ls_tester.out')

if __name__ == "__main__":
    main()

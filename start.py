#!/bin/python

import os

def main():
    os.system('make -C $(pwd)/tester')
    os.system('tester/a.out')
    os.system('rm tester/a.out')

if __name__ == "__main__":
    main()

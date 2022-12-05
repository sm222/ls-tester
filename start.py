#!/bin/python

import os

def main():
    os.system('make -C $(pwd)/tester')
    os.system('tester/a.out')
    # if (tester/text/result.txt == 1)
    #     os.system('rm tester/text/result.txt')

if __name__ == "__main__":
    main()

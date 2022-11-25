#!/bin/python

import os

def main():
    os.system('make -C $(pwd)/main')
    os.system('main/a.out')

if __name__ == "__main__":
    main()

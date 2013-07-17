#!/bin/bash

px=$1

convert -resize x${px} -gravity center -crop ${px}x${px}+0+0 WikifyMe.png -flatten -colors 256 icon${px}.png

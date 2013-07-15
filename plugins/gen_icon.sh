#!/bin/bash

convert -resize x24 -gravity center -crop 24x24+0+0 WikifyMe.png -flatten -colors 256 icon.pn

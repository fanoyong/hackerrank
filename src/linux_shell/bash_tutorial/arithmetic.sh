#!/bin/bash

read a

awk "BEGIN {printf \"%.3f\n\", $a}"

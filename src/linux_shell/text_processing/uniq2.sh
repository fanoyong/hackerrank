#!/bin/bash

uniq -c | tr -s ' ' | cut -d $' ' -f2-

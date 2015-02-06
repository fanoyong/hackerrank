#!/bin/bash

uniq -i -c | tr -s ' ' | cut -d $' ' -f2-

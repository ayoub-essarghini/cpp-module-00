#!/bin/bash

git add .
if [ -n "$1" ]; then
    git commit -m "$1"
    git push
else
    echo "Please enter a commit message"
fi


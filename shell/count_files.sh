#!/bin/bash
# 현재 디렉토리 파일 개수 출력

count=$(ls | wc -l)
echo "현재 디렉토리: $(pwd)"
echo "파일 개수: $count"

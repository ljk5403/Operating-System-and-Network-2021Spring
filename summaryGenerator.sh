#!/usr/bin/env bash
# Generator
for i in {1..15}
do
  cat "操作系统与网络 L"$i".md" >> "操作系统与网络-总集.md"
  echo >> "操作系统与网络-总集.md"
done

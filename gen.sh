#!/bin/bash

# init
function pause(){
   read -p "$*"
}


if ! [ -L "./index.aspt" ]; then
  ln -s /users/ant/index/index.aspt .
fi

if ! [ -L "./doclist.aspt" ]; then
  ln -s /users/ant/index/doclist.aspt .
fi

AFFILIATION=`grep "^ *affiliation.*=" ltw.conf | cut -f 2 -d =`
AFFILIATION=${AFFILIATION/ /}
echo "affiliation: $AFFILIATION"
TASK=`grep "^ *task.*=" ltw.conf | cut -f 2 -d =`
TASK=${TASK/ /}
echo "task: $TASK"
NAME=`grep "^ *name.*=" ltw.conf | cut -f 2 -d =`
NAME=${NAME/ /}
echo "name: $NAME"
ID=`grep "^ *id.*=" ltw.conf | cut -f 2 -d =`
ID=${ID/ /}
ID=`echo -n $ID`

SOURCE_LANG=`grep "^ *source_lang.*=" ltw.conf | cut -f 2 -d =`
SOURCE_LANG=${SOURCE_LANG/ /}
SOURCE_LANG=`echo -n $SOURCE_LANG`
echo "topic language: $SOURCE_LANG"

TARGET_LANG=`grep "^ *target_lang.*=" ltw.conf | cut -f 2 -d =`
TARGET_LANG=${TARGET_LANG/ /}
TARGET_LANG=`echo -n $TARGET_LANG`
echo "target language: $TARGET_LANG"

TOPIC_PATH=`grep "^ *topic_path.*=" ltw.conf | cut -f 2 -d =`
TOPIC_PATH=${TOPIC_PATH/ /}
TOPIC_PATH=`echo -n $TOPIC_PATH`

LANG_TASK=
S_CODE=
T_CODE=

if [ "$SOURCE_LANG" == "zh" ]
then
  S_CODE="C"
fi
if [ "$SOURCE_LANG" == "en" ]
then
  S_CODE="E"
fi
if [ "$SOURCE_LANG" == "ja" ]
then
  S_CODE="J"
fi
if [ "$SOURCE_LANG" == "ko" ]
then
  S_CODE="K"
fi

if [ "$TARGET_LANG" == "zh" ]
then
  T_CODE="C"
fi
if [ "$TARGET_LANG" == "en" ]
then
  T_CODE="E"
fi
if [ "$TARGET_LANG" == "ja" ]
then
  T_CODE="J"
fi
if [ "$TARGET_LANG" == "ko" ]
then
  T_CODE="K"
fi

LANG_TASK=${S_CODE}2${T_CODE}

OUT=${AFFILIATION}_${LANG_TASK}_${TASK}_${ID}_${NAME}.xml

if [ -z $OUT ]; then
  "No output file specified"
  exit
fi

echo "Output to: \"$OUT\""

if [ -f $OUT ]; then
  pause "The run file is already existing, are you sure to override it? Press Ctrl-C to stop running me"
fi

ltw -lowercase -targets:1 -anchors:250 $TOPIC_PATH/$SOURCE_LANG-10crosslink-topics/*.xml > $OUT

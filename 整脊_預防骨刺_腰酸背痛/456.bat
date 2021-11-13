ffmpeg -ss 00:00:10 -t 00:00:10 -i "videoplayback.mp4" -s 320x240 -b:v 500k -vcodec libx264 -r 29.97 -acodec libvo_aacenc -b:a 48k -ac 2 -ar 44100 -profile:v baseline -level 3.0 -f mp4 -y  "01.mp4"
ffmpeg -ss 00:00:26 -t 00:00:10 -i "videoplayback.mp4" -s 320x240 -b:v 500k -vcodec libx264 -r 29.97 -acodec libvo_aacenc -b:a 48k -ac 2 -ar 44100 -profile:v baseline -level 3.0 -f mp4 -y  "02.mp4"
ffmpeg -ss 00:00:40 -t 00:00:07 -i "videoplayback.mp4" -s 320x240 -b:v 500k -vcodec libx264 -r 29.97 -acodec libvo_aacenc -b:a 48k -ac 2 -ar 44100 -profile:v baseline -level 3.0 -f mp4 -y  "03.mp4"
ffmpeg -ss 00:00:50 -t 00:00:37 -i "videoplayback.mp4" -s 320x240 -b:v 500k -vcodec libx264 -r 29.97 -acodec libvo_aacenc -b:a 48k -ac 2 -ar 44100 -profile:v baseline -level 3.0 -f mp4 -y  "04.mp4"

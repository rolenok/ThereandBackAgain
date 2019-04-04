default: heat_distribution.c
	cc heat_distribution.c -o heat

video:
	ffmpeg -pattern_type glob -framerate 50 -i "*.pgm" heat.mp4

.PHONY: clean
clean:
	-rm *.pgm
	-rm heat
	-rm *.mp4

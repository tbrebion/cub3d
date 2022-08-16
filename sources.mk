## SOURCES.MK ##

## SRC ##

SOURCES		+=                           		\
		src/cub3d.c                         	\


## SRC/UTILS ##

SOURCES		+=                           		\
		src/utils/is_empty_str.c            	\
		src/utils/free_split.c              	\
		src/utils/utils.c                   	\


## SRC/RENDER ##

SOURCES		+=                           		\
		src/render/draw.c                   	\
		src/render/render.c                 	\


## SRC/GARBAGE_COLLECTOR ##

SOURCES		+=                           		\
		src/garbage_collector/garcol.c      	\


## SRC/PARSING ##

SOURCES		+=                           		\
		src/parsing/get_game_params.c       	\
		src/parsing/save_map_loop.c         	\
		src/parsing/save_file.c             	\
		src/parsing/checker_map.c           	\
		src/parsing/param_handlers.c        	\
		src/parsing/nb_col_line.c           	\
		src/parsing/check_init_file.c       	\
		src/parsing/save_map.c              	\
		src/parsing/maps_utils.c            	\


## SRC/TEST ##

SOURCES		+=                           		\
		src/TEST/test.c                     	\



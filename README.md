# FDF
First graphic project in C. Purpose of assignment - representation of a landscape. Using learning graphic library "mlx" (XLib). 

You need MLX library as a system library to make this project.
define.h file contain control defines.
Use make to compile this project.

This project can take any file as its argument. If it will find data for points to draw and will draw the graphic map representation. You can move, rotate and scale it. Also you can use help button to see controls help.

main.c - contains functions that define a general program structure.
initialize.c - contains functions that initialize main program "id" structure, establish connection to mlx lib, window creation and so on.
config.c - contains function that configure program options.
config_parse.c - contains functions that parsing options from fdf.cfg file.
map_parser.c and map_parser_check_read.c - contain functions for read, check, validation of map file and creation an array of map points.
intro_and_help.c - contains functions responsible for intro screen and help button visualization.
images_and_xpm.c - contains functions to work with mlx images and xpm images.
map_recalculation.c - contains functions which is need to check any transformation need to points during redrawing of image.
point_draw_line.c - line drawing functions.
point_draw.c - point drawing functions.
controls.c / controls_keycode_functions.c - mouse and keyboard control functions.
compass.c - this file contains functions that draw orientation help compass.
point_transformation.c / point_check_vision.c / point_scale.c / point_shift.c / point_rotation.c - point transformation functions.

additional_stuff.c - contains some error management function and put text to window function. 

fdf.cfg - contain some options you can change for this program (MLX lib do not give a capability to change XPM image size, so be ready for this).
"assets" folder contains XPM images used by this project.
"test_maps" folder contains map files to check and test this program.

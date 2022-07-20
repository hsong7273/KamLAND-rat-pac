{
name: "GEO",
index: "world",	//rock_shell
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "", // world volume has no mother
type: "toroidal",
n: 2,
z_edge:   [ -10500.0, 6500.0, 16500.0, ],	// mm 
rho_edge: [ 10000.0, 10000.0, 0.0, ], 
z_origin: [ -10500.0, 6500.0, ], 
material: "rock",
color: [0.67, 0.29, 0.0],
invisible: 1,
position: [0.0, 0.0, 0.0, ], //rot: null,
}

{
"name": "PMTINFO_test",
"valid_begin": [0, 0],
"valid_end": [0, 0],
"x": [ 0.0, 600.0, 0.0, ],
"y": [ 0.0, 800.0, 0.0, ],
"z": [ -1000.0, 0.0, 1000.0, ],
"dir_x": [ 1.0, 0.0, 0.0, ],
"dir_y": [ 0.0, 0.0, 0.0, ],
"dir_z": [ 0.0, 1.0, 1.0, ],
}
{
"name": "PMTINFO_test2",
"valid_begin": [0, 0],
"valid_end": [0, 0],
"x": [ -386.507036, 0.000000, ],
"y": [ -0.000000, -386.507036, ],
"z": [ 7990.657815, 7990.657815, ],
}

{ 
name: "GEO", 
index: "pmts", 
valid_begin: [0, 0], 
valid_end: [0, 0], 
mother: "world", 
type: "pmtarray", 
//pmt_model: "masked_17inch",
pmt_model: "r3600_17inch", 
//pmt_model: "r11780_hqe",  
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_test",
//orientation: "manual",
orientation: "point",
orient_point: [0.0, 0.0, 0.0], 
invisible: 0,
} 
{
name: "GEO",
index: "mask_17inch",			
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "world",
type: "toroidalarray",
n: 2, 
z_edge: [ -26.0, 0.0, 100.086, ], //mm
rho_edge: [ 251.837, 254.1, 218.305, ],
z_origin: [ 0.0, 0.0, ],
pos_table: "PMTINFO_test",
orientation: "point", 
orient_point: [0.0, 0.0, 0.0],
material: "acrylicBlack_kamland",
color: [ 0.6, 0.6, 0.7, 0.1, ],
invisible: 0,
}
















// KamLAND detector geometry
//
// Facility: 
//			world, cavern, deck, water_pool, LS_tank, OB, acrylic_layer, IB, LS, black_sheet, pillars,
// Inner Detector: 
//			Detectors (CCD, PMT17, PMT20), 
//			ScintillatorPlumbing (attachment_plate, lower_pipe, donut_pipe_R/L/T/B,  donut_flanges), 
//			BellMouth (donut_pipe_BMV, donut_pipe_BMH_1/2/3/4), 
// Outer Detector: 
//			OD_20inch, OD_5inch, IB/OB_8inch, tyvek_sheet_Upper/Lower,
// Calibration System:
//


// Facillity
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
name: "GEO",
index: "cavern",	//vis_cavern
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "world", 
type: "toroidal", 
n: 3, 
z_edge:   [ -10000.0, 6500.0, 9700.0, 16000.0, ],	// mm 
rho_edge: [ 9500.0, 9500.0, 8944.830, 0.0, ], 
z_origin: [ -10000.0, 6500.0, 6500.0, ], 
material: "air",
color: [ 0.0, 0.4, 0.4, 0.2],
invisible: 0,
position: [0.0, 0.0, 0.0, ], //rot: null,
}

{
name: "GEO",
index: "deck",		//roof of detector
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "cavern",  
type: "tube",
r_max: 8830, 	//mm 
r_min: 2006,
size_z: 2.25, 
material: "stainless_steel",
color: [ 0.0, 1.0, 0.0, ],
invisible: 0, 
position: [ 0.0, 0.0, 9997.75, ], 	//mm rot: null, 
}

{
name: "GEO",
index: "water_pool",		
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "cavern",
type: "toroidal",
n: 2,
z_edge:   [ -10000.0, 6500.0,  9700.0, ],	// mm 
rho_edge: [ 9500.0, 9500.0, 8944.830, ], 
z_origin: [ -10000.0, 6500.0, ], 
material: "water",
color: [ 0.0, 0.0, 0.7, 0.3, ],
invisible: 0,
position: [ 0.0, 0.0, 0.0, ], //rot: null, 
}

//surface: water_pool & cavern 
//surface: water_pool & LS_Tank: tyvek_opsurf

{
name: "GEO",
index: "LS_Tank",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "water_pool",
type: "toroidal",
n: 3, 
z_edge: [ -9000.0, 0.0, 8774.964, 9700.0, ],	// mm 
rho_edge: [ 0.0, 9000.0, 2000.0, 2000.0, ], 
z_origin: [ 0.0, 0.0, 0.0, ],
material: "stainless_steel",
color: [ 0.6, 0.6, 0.7, 0.4, ],
invisible: 0,
//position: [0, 0, 0],	//rot: null, 
}

// surface: LS_Tank & OB 

{
name: "GEO",
index: "OB",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "LS_Tank", 
type: "toroidal",
n: 3, 
z_edge: [ -8983.0, 2.0, 8764.964, 9700.0, ],	// mm
rho_edge: [ 0.0, 8985.0,  1988.0, 1988.0, ], 
z_origin: [ 2.0, 0.0, 0.0, ],
material: "mineral_oil",
color: [ 0.7, 0.4, 0.5, 0.1, ],
invisible: 0,
//position: [0, 0, 0], 	//rot: null, 
}

// acrylic_frame 

{
name: "GEO",
index: "acrylic_layer",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "OB",
type: "toroidal",
n: 4, 
z_edge: [ -8962.128, -8227.269, 0.0, 8110.262, 9700.0],	// mm
rho_edge: [ 612.0, 612.0, 8250.0, 1512.0, 1512.0, ], 
z_origin: [ 0.0, 0.0, 0.0, 0.0, ],
material: "acrylic_kamland",
color: [ 0.8, 0.8, 0.8, 0.1, ],
invisible: 0,
//position: [0, 0, 0], //rot: null, 
}

{
name: "GEO",
index: "IB",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "acrylic_layer", 
type: "toroidal",
n: 4, 
z_edge: [ -8962.12837, -8224.26905, 0.0, 8107.26239, 9700.0, ],	//mm
rho_edge: [ 612.0, 612.0, 8247.0, 1512.0, 1512.0, ],
z_origin: [ 0.0, 0.0, 0.0, 0.0, ],
material: "mineral_oil",
color: [ 0.6, 0.6, 0.7, 0.1, ],
invisible: 0,
//position: [0, 0, 0], //rot: null, 
}

// balloon_strap 

{
name: "GEO",
index: "LS",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "toroidal",
n: 5, 
z_edge: [ -6500.0, 0.0, 5052.141, 7215.591, 8100.0, 9700.0, ], //mm
rho_edge: [0.0, 6500.0, 4089.727, 1429.697, 1000.0, 1000.0, ],
z_origin: [ 0.0, 0.0, -10000000.0, 8100.0, 0.0, ],
material: "scintillator_kamland",
color: [ 0.6, 0.3, 1.0, 0.2, ],
invisible: 0,
position: [0, 0, 0], //rot: null, 
}

// surface: OB & black_sheet 

{
name: "GEO",
index: "black_sheet",
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "OB",
type: "sphere",
r_max: 8500.1, 	//mm
r_min: 8500.0,
theta_start: 10.164249, 
theta_delta:  165.619021, 
phi_start: 0.0, 
phi_delta: 360.0, 
material: "acrylic_black",
color: [ 0.1, 0.1, 0.1, 1.0, ],
invisible: 0,
}

{ //position table for pillars
name: "pillar_pos",
valid_begin: [0, 0],
valid_end: [0, 0],
x: [ 0.0, 5290.07, 8559.51, 8559.51, 5290.07, 0.0, -5290.07, -8559.51, -8559.51, -5290.07, ],
y: [ 9000.0, 7281.15, 2781.15, -2781.15, -7281.15, -9000.0, -7281.15, -2781.15, 2781.15, 7281.15, ],
z: [ -6500.0, -6500.0, -6500.0, -6500.0, -6500.0, -6500.0, -6500.0, -6500.0, -6500.0, -6500.0, ],
dir_x: [ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, ],
dir_y: [ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, ],
dir_z: [ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, ],
}
{
name: "GEO",
index: "pillars",
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "water_pool", 
type: "tubearray",
r_max: 254.0, 	//mm
r_min: 238.0, 
size_z: 3500.0, 
pos_table: "pillar_pos",
orientation: "manual",
material: "stainless_steel",
color: [0.0, 0.0, 1.0, ],
invisible: 0,
}

{
name: "GEO",
index: "inner_LS",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "revolve",
z: [ -1920.0, -1870.0, -1820.0, -1770.0, -1720.0, -1670.0, -1620.0, -1570.0, -1520.0, -1470.0, -1420.0, -1370.0, -1320.0, -1270.0, -1220.0, -1170.0, -1120.0, -1070.0, -1020.0, -970.0, -920.0, -870.0, -820.0, -770.0, -720.0, -670.0, -620.0, -570.0, -520.0, -470.0, -420.0, -370.0, -320.0, -270.0, -220.0, -170.0, -120.0, -70.0, -20.0, 30.0, 80.0, 130.0, 180.0, 230.0, 280.0, 330.0, 380.0, 430.0, 480.0, 530.0, 580.0, 630.0, 680.0, 730.0, 780.0, 830.0, 880.0, 930.0, 980.0, 1030.0, 1080.0, 1130.0, 1180.0, 1230.0, 1280.0, 1330.0, 1380.0, 1430.0, 1480.0, 1530.0, 1580.0, 1630.0, 1680.0, 1730.0, 1780.0, 1830.0, 1880.0, 1930.0, 1980.0, 2030.0, 2080.0, 2130.0, 2180.0, 2230.0, 2280.0, 2330.0, 2380.0, 2430.0, 2480.0, 2530.0, 2580.0, 2630.0, 2680.0, 2730.0, 2780.0, 2830.0, 2880.0, 2930.0, 2980.0, 3030.0, 3080.0, 3130.0, 3180.0, 3230.0, 3280.0, 3330.0, 3380.0, 3430.0, 3480.0, 3530.0, 3580.0, 3630.0, 3680.0, 3730.0, 3780.0, 3830.0, 3880.0, 3930.0, 3980.0, 4030.0, 4080.0, 4130.0, 4180.0, 4230.0, 4280.0, 4330.0, 4380.0, 4430.0, 4480.0, 4530.0, 4580.0, 4630.0, 4680.0, 4730.0, 4780.0, 4830.0, 4880.0, 4930.0, 4980.0, 5030.0, 5080.0, 5130.0, 5180.0, 5230.0, 5280.0, 5330.0, 5380.0, 5430.0, 5480.0, 5530.0, 5580.0, 5630.0, 5680.0, 5730.0, 5780.0, 5830.0, 5880.0, 5930.0, 5980.0, 6030.0, 6080.0, 6130.0, 6180.0, 6230.0, 6280.0, 6330.0, 6380.0, 6430.0, 6480.0, 6530.0, 6580.0, 6630.0, 6680.0, 6730.0, 6780.0, 6830.0, 6880.0, 6930.0, 6980.0, 7030.0, 7080.0, 7130.0, 7180.0, 7230.0, 7280.0, 7330.0, 7380.0, 7430.0, 7480.0, 7530.0, 7580.0, 7630.0, 7680.0, 7730.0, 7780.0, 7830.0, 7880.0, 7930.0, 7980.0, 8030.0, 8080.0, 8130.0, 8180.0, 8230.0, 8280.0, 8330.0, 8380.0, 8430.0, 8480.0, ],  
r_max: [ 0.0, 435.316, 611.555, 743.976, 853.229, 947.365, 1030.53, 1105.21, 1173.03, 1235.11, 1292.280, 1345.18, 1394.27, 1439.97, 1482.57, 1522.33, 1559.49, 1594.21, 1626.65, 1656.96, 1685.23, 1711.58, 1736.09, 1758.83, 1779.89, 1799.31, 1817.14, 1833.44, 1848.24, 1861.59, 1873.5, 1884.01, 1893.15, 1900.92, 1907.35, 1912.46, 1916.25, 1918.72, 1919.9, 1919.77, 1918.33, 1915.59, 1911.54, 1906.17, 1899.47, 1891.43, 1882.02, 1871.23, 1859.03, 1845.4, 1830.3, 1813.7, 1795.55, 1775.81, 1754.42, 1731.33, 1706.46, 1679.73, 1651.06, 1620.34, 1587.45, 1552.26, 1514., 1474.28, 1431.08, 1384.74, 1335.45, 1286.89, 1239.81, 1194.12, 1149.78, 1106.74, 1064.95, 1024.35, 984.924, 946.618, 909.4, 873.238, 838.101, 803.959, 770.786, 738.557, 707.248, 676.836, 647.301, 618.623, 590.783, 563.764, 537.549, 512.122, 487.47, 463.577, 440.43, 418.018, 396.327, 375.348, 355.068, 335.479, 316.57, 298.333, 280.759, 263.839, 247.566, 231.933, 216.933, 202.559, 188.805, 175.665, 163.134, 151.207, 139.877, 129.142, 118.997, 109.437, 100.46, 92.06, 84.2356, 76.9833, 70.3003, 64.184, 58.6322, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, ], 
material: "scintillator_kamland",
color: [ 0.6, 0.3, 1.0, 0.2, ],
invisible: 0,
position: [0, 0, 0], //rot: null, 
}
//####################################################################################################
//####################################################################################################
// Inner Detector

// Detectors
{ //position table for CCD cameras
name: "CCD_pos",
valid_begin: [0, 0],
valid_end: [0, 0],
x: [ 6668.90, -1915.41, -580.16, -1094.59, 1695.07, -1649.62, ],
y: [ 432.34, 2457.07, -5025.62, 8907.54, 1765.94, -6476.10, ],
z: [ 6028.17, 8443.58, 7443.56, 676.49, -8660.73, -6028.17, ],
}
{
name: "GEO",
index: "innerCCDs",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "OB",
type: "tubearray",
r_max: 250.0, 	//mm
size_z: 200.0, 
pos_table: "CCD_pos",
orientation: "point",
orient_point: [0.0, 0.0, 0.0],
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,	
}
{
name: "GEO",
index: "innerCCD_interior",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "innerCCDs",
type: "tube",
r_max: 249.0, 	//mm
size_z: 199.5, 
material: "air",
color: [ 0.0, 0.4, 0.4, 0.2],
invisible: 0,
}

{
name: "GEO",
index: "pmt_17inch",			
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "OB",
type: "pmtarray",
pmt_model: "r3600_17inch", 
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner_17inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_17less",
orientation: "point", // Aim all PMTs at a point
	     	      // "manual" means there is a dir_x, dir_y, dir_z
	              // in pos_table for manual orientation of PMTs
orient_point: [0.0, 0.0, 0.0],
}

{
name: "GEO",
index: "pmt_20inch",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "OB",
type: "pmtarray",
pmt_model: "r3600_20inch", 
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner_20inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_20less",
orientation: "point", // Aim all PMTs at a point
	     	      // "manual" means there is a dir_x, dir_y, dir_z
	              // in pos_table for manual orientation of PMTs
orient_point: [0.0, 0.0, 0.0],
}

// ScintillatorPlumbing
//surface: IB & support_ring, attachment_plate, lower_pipe, donut_pipe_R/L/T/B, donut_flanges: Stainless_opsurf

{
name: "GEO",
index: "support_ring",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "tube",
r_max: 500.0, 	//mm
r_min: 450.0,
size_z: 2.0, 
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,
position: [ 0.0, 0.0, -6500.0, ], 
}

{
name: "GEO",
index: "attachment_plate",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "tube",
r_max: 170.0, 	//mm
r_min: 45.0,
size_z: 8.0, 
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,
position: [ 0.0, 0.0, -6500.0, ], 
}

{
name: "GEO",
index: "lower_pipe",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "tube",
r_max: 35.0, 	//mm
r_min: 34.0,
size_z: 370.0, 
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,
position: [ 0.0, 0.0, -8620.0, ], 
}

{
name: "GEO",
index: "donut_pipe_R",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "torus",
r_max: 35.0, 	//mm
r_min: 34.0,
r_torus: 825.0, 
phi_start: 0.0, 
phi_delta: 180.0, 
material: "acrylic_black",
color: [ 0.1, 0.1, 0.1, 1.0, ],
invisible: 0,
position: [ 300.0, 0.0, -7400.0, ], 
rotation: [ -90.0, 0.0, 90.0, ], 
}
{
name: "GEO",
index: "donut_pipe_L",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "torus",
r_max: 35.0, 	//mm
r_min: 34.0,
r_torus: 825.0, 
phi_start: 0.0, 
phi_delta: 180.0, 
material: "acrylic_black",
color: [ 0.1, 0.1, 0.1, 1.0, ],
invisible: 0,
position: [ -300.0, 0.0, -7400.0, ], 
rotation: [ -90.0, 0.0, -90.0, ], 
}

{
name: "GEO",
index: "donut_pipe_T",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "tube",
r_max: 35.0, 	//mm
r_min: 34.0,
size_z: 265.4, 
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,
position: [ 0.0, 0.0, -6575.0, ], 
rotation: [ 0.0, -90.0, 0.0, ], 
}
{
name: "GEO",
index: "donut_pipe_B",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "tube",
r_max: 35.0, 	//mm
r_min: 34.0,
size_z: 265.4, 
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,
position: [ 0.0, 0.0, -8225.0, ], 
rotation: [ 0.0, -90.0, 0.0, ], 
}

{ //position table for donut flanges
name: "flange_pos",
valid_begin: [0, 0],
valid_end: [0, 0],
x: [ 282.7, 282.7, -282.7, -282.7,  ],
y: [ 0.0, 0.0, 0.0, 0.0, ],
z: [ -6575.0, -8225.0, -6575.0, -8225.0, ],
dir_x: [ -1.0, -1.0, -1.0, -1.0, ],
dir_y: [ 0.0, 0.0, 0.0, 0.0, ],
dir_z: [ 0.0, 0.0, 0.0, 0.0, ],
}
{
name: "GEO",
index: "donut_flanges",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "tubearray",
r_max: 57.0, 	//mm
r_min: 34.0,
size_z: 17.3, 
pos_table: "flange_pos",
orientation: "manual",
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,
}

// BellMouth

{ //position table for donut pipe BMV
name: "pipe_pos",
valid_begin: [0, 0],
valid_end: [0, 0],
x: [ -2161.500, -2143.008, -2087.849, -1996.966, -1871.914, -1714.833, -1528.411, -1315.838, -1080.750, -827.170, -559.437, -282.132, -0.000, 282.132, 559.437, 827.170, 1080.750, 1315.838, 1528.411, 1714.833, 1871.914, 1996.966, 2087.849, 2143.008, 2161.500, 2143.008, 2087.849, 1996.966, 1871.914, 1714.833, 1528.411, 1315.838, 1080.750, 827.170, 559.437, 282.132, 0.000, -282.132, -559.437, -827.170, -1080.750, -1315.838, -1528.411, -1714.833, -1871.914, -1996.966, -2087.849, -2143.008, ],  
y: [ -0.000, -282.132, -559.437, -827.170, -1080.750, -1315.838, -1528.411, -1714.833, -1871.914, -1996.966, -2087.849, -2143.008, -2161.500, -2143.008, -2087.849, -1996.966, -1871.914, -1714.833, -1528.411, -1315.838, -1080.750, -827.170, -559.437, -282.132, -0.000, 282.132, 559.437, 827.170, 1080.750, 1315.838, 1528.411, 1714.833, 1871.914, 1996.966, 2087.849, 2143.008, 2161.500, 2143.008, 2087.849, 1996.966, 1871.914, 1714.833, 1528.411, 1315.838, 1080.750, 827.170, 559.437, 282.132, ],  
z: [ 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, 8050.0, ],
dir_x: [ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, ], 
dir_y: [ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, ], 
dir_z: [ 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, ],
rot_x: [ 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, ],
rot_y: [ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, ],
rot_z: [ 0.0, 352.5, 345.0, 337.5, 330.0, 322.5, 315.0, 307.5, 300.0, 292.5, 285.0, 277.5, 270.0, 262.5, 255.0, 247.5, 240.0, 232.5, 225.0, 217.5, 210.0, 202.5, 195.0, 187.5, 180.0, 172.5, 165.0, 157.5, 150.0, 142.5, 135.0, 127.5, 120.0, 112.5, 105.0, 97.5, 90.0, 82.5, 75.0, 67.5, 60.0, 52.5, 45.0, 37.5, 30.0, 22.5, 15.0, 7.5,  ],
}
{
name: "GEO",
index: "donut_pipe_BMV",
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "torusarray",
r_max: 19.6, 
r_min: 17.5, 
r_torus: 1102.3, 
phi_start: 0.0, 
phi_delta: 65.0, 
pos_table: "pipe_pos", 
rotate_solids: "manual", 
orientation: "manual", 
material: "stainless_steel",
color: [ 0.6, 0.6, 0.7, 0.4, ],
invisible: 0,
//position: [ -2161.5*cos(-th1), -2161.5*sin(-th1), 8050.0, ],
//rotation: [ 90.0, 0.0, 0.0, ]
}

//surface: IB & donut_pipe_BMH_1/2/3/4: Stainless_opsurf

{
name: "GEO",
index: "donut_pipe_BMH_1",		
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "torus",
r_max: 19.6, 
r_min: 17.5, 
r_torus: 1128.86, 
material: "stainless_steel",
color: [ 0.6, 0.6, 0.7, 0.4, ],
invisible: 0,
position: [ 0.0, 0.0, 7792.67, ],
}
{
name: "GEO",
index: "donut_pipe_BMH_2",		
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "torus",
r_max: 19.6, 
r_min: 17.5, 
r_torus: 1338.03, 
material: "stainless_steel",
color: [ 0.6, 0.6, 0.7, 0.4, ],
invisible: 0,
position: [ 0.0, 0.0, 7363.8, ],
}
{
name: "GEO",
index: "donut_pipe_BMH_3",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "torus",
r_max: 19.6, 
r_min: 17.5, 
r_torus: 1470.29, 
material: "stainless_steel",
color: [ 0.6, 0.6, 0.7, 0.4, ],
invisible: 0,
position: [ 0.0, 0.0, 7224.43],
}
{
name: "GEO",
index: "donut_pipe_BMH_4",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "torus",
r_max: 19.6, 
r_min: 17.5, 
r_torus: 1708.86, 
material: "stainless_steel",
color: [ 0.6, 0.6, 0.7, 0.4, ],
invisible: 0,
position: [ 0.0, 0.0, 7063.51, ],
}

//####################################################################################################
//####################################################################################################

// Outer Detector

// Detectors
{
name: "GEO",
index: "pmtOD_20inch",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "water_pool",
type: "pmtarray",
pmt_model: "r3600_20inch", 
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/outer_20inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_outer_20less",
orientation: "manual", 
invisible: 1, 
}

{
name: "GEO",
index: "pmtOD_5inch",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "cavern",
type: "pmtarray",
pmt_model: "ETI_9372A_5inch", 
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/outer_5inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_outer_5inch",
orientation: "manual", 
rotation: "manual",
invisible: 0, 
}
//surface: cavern & 5inch_sleeve: stainless_steel
{
name: "GEO",
index: "5inch_sleeve",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "cavern",
type: "tubearray",
pos_table: "PMTINFO_outer_5inch",
orientation: "manual",
r_max: 65.0, 	//mm
r_min: 64.0, 
size_z: 54.0, 
material: "stainless_steel",
color: [ 0.0, 0.0, 1.0, ],
invisible: 0,
}

{
name: "GEO",
index: "pmtIB_8inch",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB",
type: "pmtarray",
pmt_model: "R5912_8inch", 
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner_8inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_inner_8inch",
orientation: "manual", 
//rotation: "manual",
invisible: 0, 
}
{
name: "GEO",
index: "pmtOB_8inch",	
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "OB",
type: "pmtarray",
pmt_model: "R5912_8inch", 
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/outer_8inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_outer_8inch",
orientation: "manual", 
//rotation: "manual",
invisible: 0, 
}

//surface: water_pool & tyvek_sheet_Upper: tyvek
{
name: "GEO",
index: "tyvek_sheet_Upper",		
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "water_pool",  
type: "tube",
r_max: 9287.09, 	//mm 
r_min: 2958.04,
size_z: 0.5, 
material: "tyvek",
//color: [ ],
invisible: 0, 
position: [ 0.0, 0.0, 8500.0, ], 	//mm  
}
//surface: water_pool & tyvek_sheet_LOWer: tyvek
{
name: "GEO",
index: "tyvek_sheet_Lower",		
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "water_pool",  
type: "tube",
r_max: 9500.0, 	//mm 
r_min: 2958.04,
size_z: 0.5, 
material: "tyvek",
//color: [ ],
invisible: 0, 
position: [ 0.0, 0.0, -8500.0, ], 	//mm
}















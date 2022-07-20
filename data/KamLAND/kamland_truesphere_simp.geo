// Simplified KamLAND detector geometry

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
type: "sphere",
r_max: 9000.0,
r_min: 0.0, 
theta_start: 0.0, 
theta_delta: 180.0,
phi_start: 0.0, 
phi_delta: 360.0, 
material: "stainless_steel",
color: [ 0.6, 0.6, 0.7, 0.4, ],
invisible: 0,
position: [ 0.0, 0.0, 0.0, ],	//rot: null, 
}

// surface: LS_Tank & OB 

{
name: "GEO",
index: "OB",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "LS_Tank", 
type: "sphere",
r_max: 8985.0,
r_min: 0.0, 
theta_start: 0.0, 
theta_delta: 180.0, 
phi_start: 0.0, 
phi_delta: 360.0, 
material: "mineral_oil",
color: [ 0.7, 0.4, 0.5, 0.1, ],
invisible: 0,
position: [ 0.0, 0.0, 0.0, ], 	//rot: null, 
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
theta_start: 10.164, 
theta_delta:  165.619, 
phi_start: 0.0, 
phi_delta: 360.0, 
material: "acrylic_black",
//material: "acrylic_kamland",
color: [ 0.1, 0.1, 0.1, 1.0, ],
invisible: 0,
}

// acrylic_frame 

{	//omittable
name: "GEO",
index: "acrylic_layer",		
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "OB",
type: "sphere",
r_max: 8250.0, 
r_min: 0.0, 
theta_start: 0.0,  
theta_delta: 180.0, 
phi_start: 0.0, 
phi_delta: 360.0, 
material: "acrylic_kamland",
//material: "acrylic_white",
color: [ 0.8, 0.8, 0.8, 0.1, ],
invisible: 0,
}

{
name: "GEO",
index: "IB",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "acrylic_layer", 
type: "sphere",
r_max: 8247.0, 
r_min: 0.0, 
theta_start: 0.0, 
theta_delta: 180.0, 
phi_start: 0.0, 
phi_delta: 360.0, 
material: "mineral_oil",
color: [ 0.6, 0.6, 0.7, 0.1, ],
invisible: 0,
//position: [ 0.0, 0.0, 0.0, ], //rot: null, 
}

// balloon_strap 

{
name: "GEO",
index: "LS",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "sphere",
r_max: 6500.0, 
r_min: 0.0, 
theta_start: 0.0,  
theta_delta: 180.0, 
phi_start: 0.0, 
phi_delta: 360.0, 
//material: "scintillator_kamland",
material: "scintillator",
color: [ 0.6, 0.3, 1.0, 0.2, ],
invisible: 0,
position: [ 0.0, 0.0, 0.0, ], //rot: null, 
}

{
name: "GEO",
index: "inner_LS",		//precise version
valid_begin: [0, 0],
valid_end: [0, 0],
mother: "IB", 
type: "revolve",
z: [ -1920.0, -1870.0, -1820.0, -1770.0, -1720.0, -1670.0, -1620.0, -1570.0, -1520.0, -1470.0, -1420.0, -1370.0, -1320.0, -1270.0, -1220.0, -1170.0, -1120.0, -1070.0, -1020.0, -970.0, -920.0, -870.0, -820.0, -770.0, -720.0, -670.0, -620.0, -570.0, -520.0, -470.0, -420.0, -370.0, -320.0, -270.0, -220.0, -170.0, -120.0, -70.0, -20.0, 30.0, 80.0, 130.0, 180.0, 230.0, 280.0, 330.0, 380.0, 430.0, 480.0, 530.0, 580.0, 630.0, 680.0, 730.0, 780.0, 830.0, 880.0, 930.0, 980.0, 1030.0, 1080.0, 1130.0, 1180.0, 1230.0, 1280.0, 1330.0, 1380.0, 1430.0, 1480.0, 1530.0, 1580.0, 1630.0, 1680.0, 1730.0, 1780.0, 1830.0, 1880.0, 1930.0, 1980.0, 2030.0, 2080.0, 2130.0, 2180.0, 2230.0, 2280.0, 2330.0, 2380.0, 2430.0, 2480.0, 2530.0, 2580.0, 2630.0, 2680.0, 2730.0, 2780.0, 2830.0, 2880.0, 2930.0, 2980.0, 3030.0, 3080.0, 3130.0, 3180.0, 3230.0, 3280.0, 3330.0, 3380.0, 3430.0, 3480.0, 3530.0, 3580.0, 3630.0, 3680.0, 3730.0, 3780.0, 3830.0, 3880.0, 3930.0, 3980.0, 4030.0, 4080.0, 4130.0, 4180.0, 4230.0, 4280.0, 4330.0, 4380.0, 4430.0, 4480.0, 4530.0, 4580.0, 4630.0, 4680.0, 4730.0, 4780.0, 4830.0, 4880.0, 4930.0, 4980.0, 5030.0, 5080.0, 5130.0, 5180.0, 5230.0, 5280.0, 5330.0, 5380.0, 5430.0, 5480.0, 5530.0, 5580.0, 5630.0, 5680.0, 5730.0, 5780.0, 5830.0, 5880.0, 5930.0, 5980.0, 6030.0, 6080.0, 6130.0, 6180.0, 6230.0, 6280.0, 6330.0, 6380.0, 6430.0, 6480.0, 6530.0, 6580.0, 6630.0, 6680.0, 6730.0, 6780.0, 6830.0, 6880.0, 6930.0, 6980.0, 7030.0, 7080.0, 7130.0, 7180.0, 7230.0, 7280.0, 7330.0, 7380.0, 7430.0, 7480.0, 7530.0, 7580.0, 7630.0, 7680.0, 7730.0, 7780.0, 7830.0, 7880.0, 7930.0, 7980.0, 8030.0, 8080.0, 8130.0, 8180.0, 8230.0, 8280.0, 8330.0, 8380.0, 8430.0, 8480.0, 8480.0, ],  
r_max: [ 0.0, 435.316, 611.555, 743.976, 853.229, 947.365, 1030.53, 1105.21, 1173.03, 1235.11, 1292.280, 1345.18, 1394.27, 1439.97, 1482.57, 1522.33, 1559.49, 1594.21, 1626.65, 1656.96, 1685.23, 1711.58, 1736.09, 1758.83, 1779.89, 1799.31, 1817.14, 1833.44, 1848.24, 1861.59, 1873.5, 1884.01, 1893.15, 1900.92, 1907.35, 1912.46, 1916.25, 1918.72, 1919.9, 1919.77, 1918.33, 1915.59, 1911.54, 1906.17, 1899.47, 1891.43, 1882.02, 1871.23, 1859.03, 1845.4, 1830.3, 1813.7, 1795.55, 1775.81, 1754.42, 1731.33, 1706.46, 1679.73, 1651.06, 1620.34, 1587.45, 1552.26, 1514., 1474.28, 1431.08, 1384.74, 1335.45, 1286.89, 1239.81, 1194.12, 1149.78, 1106.74, 1064.95, 1024.35, 984.924, 946.618, 909.4, 873.238, 838.101, 803.959, 770.786, 738.557, 707.248, 676.836, 647.301, 618.623, 590.783, 563.764, 537.549, 512.122, 487.47, 463.577, 440.43, 418.018, 396.327, 375.348, 355.068, 335.479, 316.57, 298.333, 280.759, 263.839, 247.566, 231.933, 216.933, 202.559, 188.805, 175.665, 163.134, 151.207, 139.877, 129.142, 118.997, 109.437, 100.46, 92.06, 84.2356, 76.9833, 70.3003, 64.184, 58.6322, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 58.0, 0.0, ], 
material: "scintillator_kamland",
color: [ 0.6, 0.3, 1.0, 0.2, ],
invisible: 0,
position: [0, 0, 0], //rot: null, 
}

{ 
name: "GEO", 
index: "pmts_17inch", 
valid_begin: [0, 0], 
valid_end: [0, 0], 
mother: "OB", 
type: "pmtarray", 
//pmt_model: "r3600_17inch",  
pmt_model: "masked_17inch",
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner_17inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_TSph_17", 
orientation: "point",
orient_point: [0.0, 0.0, 0.0], 
} 
{ 
name: "GEO", 
index: "pmts_20inch", 
valid_begin: [0, 0], 
valid_end: [0, 0], 
mother: "OB", 
type: "pmtarray", 
//pmt_model: "r3600_20inch",
pmt_model: "masked_20inch",
pmt_detector_type: "idpmt",
sensitive_detector: "/mydet/pmt/inner_20inch",
efficiency_correction: 1.027,  
add_concentrator: 1, // Flag: 0 = no concentrators, 1 = concentrators
pos_table: "PMTINFO_TSph_20", 
orientation: "point",
orient_point: [0.0, 0.0, 0.0], 
} 







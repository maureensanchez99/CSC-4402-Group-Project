DROP DATABASE IF EXISTS plant_store;
CREATE DATABASE plant_store;
USE plant_store;
CREATE TABLE employee (
	employee_id VARCHAR(8),
	first_name VARCHAR(60),
	last_name VARCHAR(60),
	emplyment_type ENUM('Part-Time', 'Full-Time', 'Seasonal'),
	hours NUMERIC(3,0),
	wage NUMERIC(8,2),
	store_id VARCHAR(8),
	primary key (employee_id)
);

CREATE TABLE manager (
	manager_id VARCHAR(8) UNIQUE,
	emplyee_count INT(8) UNSIGNED NOT NULL,
	primary key (manager_id),
	foreign key (manager_id) references employee(employee_id)
);

CREATE TABLE store (
	store_id VARCHAR(8),
	state ENUM('Louisiana', 'Alabama', 'Florida'),
	city VARCHAR(60),
	street_number NUMERIC(4,0),
	street_name VARCHAR(120),
	zip_code NUMERIC(5,0),
	emplyee_count INT(8) UNSIGNED NOT NULL,
	manager_id VARCHAR(8) UNIQUE,
	primary key (store_id),
	foreign key (manager_id) references 		manager(manager_id)
);

CREATE TABLE product (
	product_id VARCHAR(8),
	price NUMERIC(8,2),
	quantity INT(8) UNSIGNED NOT NULL,
	primary key (product_id)
);

CREATE TABLE inventory (
	barcode BIGINT(8) UNSIGNED NOT NULL,
	product_id VARCHAR(16),
	primary key (barcode),
	foreign key (product_id) references product(product_id)
);



CREATE TABLE plant (
	product_id VARCHAR(16),
	type ENUM('House Plant', 'Tree', 'Bush'),
	name VARCHAR(120),
	size ENUM('Small', 'Medium', 'Large'),
	sunlight ENUM('Full Shade', 'Part Shade', 'Full Sun', 'Part Sun'),
	water ENUM('Rarely', 'Monthly', 'Bi-Weekly', 'Weekly', 'Daily'),
	humidity ENUM('Low', 'Medium', 'High'),
	primary key (product_id),
	foreign key (product_id) references product(product_id)
);

CREATE TABLE tool (
	product_id VARCHAR(16),
	type VARCHAR(60),
	brand VARCHAR(120),
	primary key (product_id),
	foreign key (product_id) references product(product_id)
);

CREATE TABLE seed (
	product_id VARCHAR(16),
	name VARCHAR(120),
	season ENUM('Summer', 'Fall', 'Winter', 'Spring'),
	zone NUMERIC(2,0),
	sunlight ENUM('Full Shade', 'Part Shade', 'Full Sun', 'Part Sun'),
	water ENUM('Rarely', 'Monthly', 'Bi-Weekly', 'Weekly', 'Daily'),
	humidity ENUM('Low', 'Medium', 'High'),
	primary key (product_id),
	foreign key (product_id) references product(product_id)
);

CREATE TABLE customer (
	customer_id VARCHAR(8),
	membership BOOL,
	state ENUM('Louisiana', 'Alabama', 'Florida'),
	city VARCHAR(60),
	street_number NUMERIC(4,0),
	street_name VARCHAR(120),
	zip_code NUMERIC(5,0),
	primary key (customer_id)

);

CREATE TABLE customer_order (
	order_id VARCHAR(16),
	order_type ENUM('Online', 'In-Person'),
	customer_id VARCHAR(8),
	order_date DATE,
	status ENUM('Ordered', 'Processing', 		'Completed'),
	primary Key (order_id)

);

CREATE TABLE order_item (
	order_id VARCHAR(16),
	product_id VARCHAR(16),
	quantity NUMERIC(8,0),
	primary key (order_id, product_id),
	foreign key (order_id) references 			customer_order(order_id)
);






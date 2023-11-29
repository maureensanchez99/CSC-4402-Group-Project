   
Drop table if exists 'store';
create table store (
	store_id		varchar(8),
  	employee_count	numeric(4,0),
  	street_number	numeric(5,0),
  	street_name		varchar(50),
  	apt_number		numeric(5,0),
  	city			varchar(50),
  	state			varchar(50),
  	zip				numeric(5,0),
  	primary key (store_id)
);

INSERT INTO store VALUES (1, 3, 325, 'Market Blvd.', NULL, 'Baton Rouge', 'Louisiana', 70806);
INSERT INTO store VALUES (2, 3, 165, 'Store Ln', NULL, 'Tampa', 'Florida', 400625);

DROP TABLE if exists 'employee';
create table employee (
	employee_id		varchar(8),
  	name_first		varchar(50),
  	name_last		varchar(50),
  	street_number	numeric(5,0),
  	street_name		varchar(50),
  	apt_number		numeric(5,0),
  	city			varchar(50),
  	state			varchar(50),
  	zip				numeric(5,0),
  	hours			numeric(2,0),
  	wage			numeric(5,2),
  	manager			bool,
  	store_id		varchar(8),
  	primary key (employee_id),
  	foreign key (store_id) references store
);

INSERT INTO employee VALUES (1, 'John', 'Smith', 175, 'Dalrymple', NULL, 'Baton Rouge', 'Louisiana', 70808, 20, 10.00, false, 1);
INSERT INTO employee VALUES (2, 'Mark', 'Baker', 283, 'Cherrydale', NULL, 'Baton Rouge', 'Louisiana', 70808, 25, 10.00, false, 1);
INSERT INTO employee VALUES (3, 'Alice', 'Jones', 846, 'North St.', NULL, 'Baton Rouge', 'Louisiana', 70806, 40, 20.00, true, 1);

INSERT INTO employee VALUES (4, 'Jessica', 'Williams', 836, 'Baker St.', NULL, 'Tampa', 'Florida', 40625, 15, 10.00, false, 2);
INSERT INTO employee VALUES (5, 'Sarah', 'Anderson', 926, 'Apple Ln.', NULL, 'Tampa', 'Florida', 40629, 20, 10.00, false, 2);
INSERT INTO employee VALUES (6, 'Paul', 'Brown', 198, 'Sheffield Ave.', NULL, 'Tampa', 'Florida', 40624, 40, 20.00, true, 2);

drop table if exists 'product';
create table product(
	product_id		varchar(8),
  	price			numeric(10,2),
  	primary key (product_id)
);

INSERT INTO product VALUES (1, 10.99);
INSERT INTO product VALUES (2, 25.00);
INSERT INTO product VALUES (3, 55.00);

INSERT INTO product VALUES (4, 15.99);
INSERT INTO product VALUES (5, 12.00);
INSERT INTO product VALUES (6, 39.99);

INSERT INTO product VALUES (7, 29.99);
INSERT INTO product VALUES (8, 29.99);
INSERT INTO product VALUES (9, 29.99);

drop table if exists 'plant';
create table plant(
	product_id		varchar(8),
  	name			varchar(50),
  	type			varchar(20),
  	size			varchar(20),
  	sunlight		varchar(20),
  	water			varchar(20),
  	humidity		varchar(20),
  	primary key (name),
  	foreign key (product_id) references product
);

INSERT INTO plant VALUES (1, 'Pothos', 'House Plant', 'Medium', 'Partial Shade', 'Daily', 'Low Humidity');
INSERT INTO plant VALUES (2, 'Desert Rose', 'Succulent', 'Small', 'Full Sun', 'Monthly', 'Low Humidity');
INSERT INTO plant VALUES (3, 'Roses', 'Bush', 'Large', 'Partial Sun', 'Weekly', 'Medium Humidity');

drop table if exists 'tool';
create table tool(
	product_id		varchar(8),
  	type			varchar(50),
  	brand			varchar(50),
  	primary key (type, brand),
  	foreign key (product_id) references product
);

INSERT INTO tool VALUES (4, 'hand shovel', 'generic');
INSERT INTO tool VALUES (5, 'large rake', 'very special');
INSERT INTO tool VALUES (6, 'brown pot', 'classy');

drop table if exists 'seed';
create table seed(
	product_id		varchar(8),
  	name			varchar(50),
  	type			varchar(20),
  	season			varchar(20),
  	zone			varchar(20),
  	sunlight		varchar(20),
  	water			varchar(20),
  	humidity		varchar(20),
  	primary key (name),
  	foreign key (product_id) REFERENCES product
);

INSERT INTO seed VALUEs (7, 'cilantro', 'herb', 'summer', '5A', 'Full Sun', 'Weekly', 'Medium Humidity');
INSERT INTO seed VALUEs (8, 'parsely', 'herb', 'fall', '9B', 'Partial Shade', 'Bi-Weekly', 'Low Humidity');
INSERT INTO seed VALUEs (9, 'brocolli', 'vegetable', 'winter', '7', 'Full Shade', 'Monthly', 'Low Humidity');

drop table if exists 'customer';
create table customer(
  	customer_id		varchar(8),
  	name_first		varchar(50),
  	name_last		varchar(50),
  	street_number	numeric(5,0),
  	street_name		varchar(50),
  	apt_number		numeric(5,0),
  	city			varchar(50),
  	state			varchar(50),
  	zip				numeric(5,0),
  	member			bool,
  	primary key (customer_id)
);

INSERT INTO customer VALUES (1, 'Jane', 'Doe', 837, 'Burch Ln.', 5, 'Baton Rouge', 'Louisiana', 70802, true);
INSERT INTO customer VALUES (2, 'Richard', 'Garcia', 926, 'Succulent Blvd.', 5, 'New Orleans', 'Louisiana', 70525, false);

INSERT INTO customer VALUES (3, 'Jeff', 'Johnson', 197, 'Random Road', 5, 'Tampa', 'Florida', 40524, true);
INSERT INTO customer VALUES (4, 'Anna', 'Davis', 496, 'Hypothetical St.', 5, 'Tampa', 'florida', 40529, false);

drop table if exists 'cust_order';
create table cust_order(
 	order_id		varchar(8),
  	order_type		varchar(20),
  	customer_id		varchar(8),
  	status			varchar(20),
  	primary key (order_id),
  	foreign key (customer_id) references customer
);

INSERT INTO cust_order VALUES (1, 'Online', 1, 'Completed');
INSERT INTO cust_order VALUES (2, 'In-Person', 1, 'In Progress');
INSERT INTO cust_order VALUES (3, 'Online', 3, 'Ready for Pickup');
INSERT INTO cust_order VALUES (4, 'In-Person', 4, 'Waiting to be Processed');

drop table if exists 'store_product';
create table store_product(
 	store_id		varchar(8) ,
  	product_id		varchar(8) ,
  	quantity		numeric(8,0),
  	primary key (store_id, product_id),
  	foreign key (store_id) references store,
  	foreign key (product_id) references product
);

INSERT INTO store_product VALUES (1, 1, 5);
INSERT INTO store_product VALUES (1, 2, 100);
INSERT INTO store_product VALUES (1, 3, 25);
INSERT INTO store_product VALUES (1, 4, 30);
INSERT INTO store_product VALUES (1, 5, 500);
INSERT INTO store_product VALUES (1, 6, 62);
INSERT INTO store_product VALUES (1, 7, 38);
INSERT INTO store_product VALUES (1, 8, 1000);
INSERT INTO store_product VALUES (1, 9, 0);

INSERT INTO store_product VALUES (2, 1, 49);
INSERT INTO store_product VALUES (2, 2, 12);
INSERT INTO store_product VALUES (2, 3, 52);
INSERT INTO store_product VALUES (2, 4, 15);
INSERT INTO store_product VALUES (2, 5, 26);
INSERT INTO store_product VALUES (2, 6, 32);
INSERT INTO store_product VALUES (2, 7, 2500);
INSERT INTO store_product VALUES (2, 8, 739);
INSERT INTO store_product VALUES (2, 9, 52);

drop table if exists 'prod_order';
create table prod_order(
 	product_id			varchar(8),
  	order_id			varchar(8),
  	quantity_ordered	numeric(7,0),
  	primary key (product_id, order_id),
  	foreign key (product_id) REFERENCES product,
  	foreign key (order_id) REFERENCES cust_order
);

INSERT INTO prod_order VAlues (5, 1, 5);
INSERT INTO prod_order values (2, 1, 2);

INSERT INTO prod_order values (9, 2, 8);
INSERT INTO prod_order values (1, 2, 12);
INSERT INTO prod_order values (3, 2, 32);

INSERT INTO prod_order values (9, 3, 10);

INSERT INTO prod_order values (4, 4, 3);
INSERT INTO prod_order values (2, 4, 9);

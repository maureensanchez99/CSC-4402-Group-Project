   
Drop table if exists 'store';
create table store (
	store_id		varchar(8),
  	employee_count	numeric(4,0),
  	street_number	numeric(5,0),
  	street_name		varchar(50),
  	apt_number		numeric(5,0),
  	city			varchar(50),
  	state			varchar(50),
  	primary key (store_id)
);
DROP TABLE if exists 'employee';
create table employee (
	employee_id		varchar(8),
  	name_last		varchar(50),
  	name_first		varchar(50),
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

drop table if exists 'product';
create table product(
	product_id		varchar(8),
  	price			numeric(10,2),
  	quanity			numeric(7,0),
	store_id		varchar(8),
  	primary key (product_id),
  	foreign key (store_id) references store
);

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

drop table if exists 'tool';
create table tool(
	product_id		varchar(8),
  	type			varchar(50),
  	brand			varchar(50),
  	primary key (type, brand),
  	foreign key (product_id) references product
);

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

drop table if exists 'customer';
create table customer(
  	customer_id		varchar(8),
  	name_last		varchar(50),
  	name_first		varchar(50),
  	street_number	numeric(5,0),
  	street_name		varchar(50),
  	apt_number		numeric(5,0),
  	city			varchar(50),
  	state			varchar(50),
  	zip				numeric(5,0),
  	member			bool,
  	primary key (customer_id)
);

drop table if exists 'cust_order';
create table cust_order(
 	order_id		varchar(8),
  	order_type		varchar(20),
  	customer_id		varchar(8),
  	status			varchar(20),
  	primary key (order_id),
  	foreign key (customer_id) references customer
);

drop table if exists 'store_product';
create table store_product(
 	store_id		varchar(8),
  	product_id		varchar(8),
  	quantity		numeric(8,0),
  	primary key (store_id, product_id),
  	foreign key (store_id) references store,
  	foreign key (product_id) references product
);

drop table if exists 'prod_order';
create table prod_order(
 	product_id			varchar(8),
  	order_id			varchar(8),
  	quantity_ordered	numeric(7,0),
  	primary key (product_id, order_id),
  	foreign key (product_id) REFERENCES product,
  	foreign key (order_id) REFERENCES cust_order
);

CREATE TABLE ticket_detail (
	id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	code VARCHAR(30) NOT NULL,
	title1 VARCHAR(30) NOT NULL,
	title2 VARCHAR(30) NOT NULL,
	title3 VARCHAR(30) NOT NULL,
	title4 VARCHAR(30) NOT NULL,
	title5 VARCHAR(30) NOT NULL,
	ticket_relation1 VARCHAR(30) NOT NULL,
	ticket_relation2 VARCHAR(30) NOT NULL,
	ticket_relation3 VARCHAR(30) NOT NULL,
	ticket_relation4 VARCHAR(30) NOT NULL,
	ticket_relation5 VARCHAR(30) NOT NULL
);


INSERT INTO ticket_detail (code, title1, title2, title3, title4, title5, ticket_relation1, ticket_relation2, ticket_relation3, ticket_relation4, ticket_relation5) 
	VALUES ("t01", "Nelly Bentham", "Blake Braucks", "Helena Stephanie", "Hope Skilling", "Andres Erlewine", "03_03_04", "01_04", "03_01_04_01", "01_02_01_01", "02_01_02_02");
	INSERT INTO ticket_detail (code, title1, title2, title3, title4, title5, ticket_relation1, ticket_relation2, ticket_relation3, ticket_relation4, ticket_relation5) 
	VALUES ("t02", "Merri Artalejo", "Natasha Biro", "Jacquelin Sprott", "Kristeen Kridel", "Nettie Camper", "03_01_02", "02_01", "03_04_04_01", "02_04_02_02", "04_03_03_04");
	INSERT INTO ticket_detail (code, title1, title2, title3, title4, title5, ticket_relation1, ticket_relation2, ticket_relation3, ticket_relation4, ticket_relation5) 
	VALUES ("t03", "Santana Cong", "Josie Kushaney", "Forrest Gallemore", "Berry Toot", "Miranda Buffkin", "02_01_01", "01_04", "03_04_01_02", "03_01_01_01", "01_02_03_03");
	INSERT INTO ticket_detail (code, title1, title2, title3, title4, title5, ticket_relation1, ticket_relation2, ticket_relation3, ticket_relation4, ticket_relation5) 
	VALUES ("t04", "Ernesto Storozuk", "Kai Boero", "Edris Karam", "Maura Wilcoxson", "Malcom Nowack", "01_03_04", "01_02", "04_02_04_01", "02_01_04_03", "02_03_03_03");
	INSERT INTO ticket_detail (code, title1, title2, title3, title4, title5, ticket_relation1, ticket_relation2, ticket_relation3, ticket_relation4, ticket_relation5) 
	VALUES ("t05", "Zelda Shamlin", "Rufina Mussman", "Sibyl Piercy", "Amina Basinski", "Mariko Suryan", "02_04_02", "04_03", "02_02_02_02", "04_02_01_02", "01_02_04_04");
	INSERT INTO ticket_detail (code, title1, title2, title3, title4, title5, ticket_relation1, ticket_relation2, ticket_relation3, ticket_relation4, ticket_relation5) 
	VALUES ("t06", "Tiana Medero", "Arlette Agans", "Doreatha Bristo", "Adina Commodore", "Emely Giampaolo", "04_03_03", "02_03", "01_03_02_01", "03_03_04_02", "04_04_04_04");
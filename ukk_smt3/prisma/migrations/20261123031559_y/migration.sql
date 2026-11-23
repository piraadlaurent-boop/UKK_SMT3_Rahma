-- CreateTable
CREATE TABLE `tbl_unit_facility` (
    `id` INTEGER NOT NULL AUTO_INCREMENT,
    `kode_facility` VARCHAR(191) NULL,

    UNIQUE INDEX `tbl_unit_facility_kode_facility_key`(`kode_facility`),
    PRIMARY KEY (`id`)
) DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;

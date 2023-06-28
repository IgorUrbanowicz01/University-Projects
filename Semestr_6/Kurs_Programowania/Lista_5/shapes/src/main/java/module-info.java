module com.lista5 {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.lista5 to javafx.fxml;
    exports com.lista5;
}

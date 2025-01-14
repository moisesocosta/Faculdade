package Enuns;

import java.util.Date;

public class Pagamento {
    private Date data;
    private StatusPagamento status;

    public Pagamento(Date data, StatusPagamento status){
        this.data = data;
        this.status = status;
    }
    public void setData(Date data) {
        this.data = data;
    }
    public void setStatus(StatusPagamento status) {
        this.status = status;
    }

    public Date getData() {
        return data;
    }
    public StatusPagamento getStatus() {
        return status;
    }

    @Override
    public String toString() {
        return "Pedido [data=" + data + ", status=" + status + "]";
    }


}

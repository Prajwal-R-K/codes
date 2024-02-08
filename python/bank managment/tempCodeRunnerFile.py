df_cust = pd.DataFrame(cust_info)
df_acc = pd.DataFrame(acc_info)
df_trans = pd.DataFrame(trans_info)

# Merge dataframes to link information
df_merged = pd.merge(df_cust, df_acc, on='cif_no')